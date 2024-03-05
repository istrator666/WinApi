#include "TestStageLevel.h"
#include "StageMap.h"

#include "EngineCore/EngineCore.h"



UTestStageLevel::UTestStageLevel()
{
}

UTestStageLevel::~UTestStageLevel()
{
}

void UTestStageLevel::BeginPlay()
{
	ULevel::BeginPlay();

	AStageMap* Stage = SpawnActor<AStageMap>();

	Player = SpawnActor<APlayer>();
	Player->SetActorLocation({ 575, 225 });
	StageMovePlayer(Player);

	SetStageUI();
	SetEQInventory();

	FightZone = SpawnActor<AFightZone>();
	FightZone->SetActive(false, 0.1f);

	PlayerFight = SpawnActor<APlayerFight>();
	PlayerFight->SetActive(false, 0.1f);

}

void UTestStageLevel::ChangeState(EStageState _State)
{
	switch (_State)
	{
	case EStageState::Move:

		break;
	case EStageState::Fight:
		FightStart();
		break;
	default:
		break;
	}

	CurState = _State;
}

void UTestStageLevel::MonsterSpawnTimeCheck(float _DeltaTime)
{
	StageprogressGauge->StageProgressGaugeUpdate(_DeltaTime);

	if (0 == StageprogressGauge->GetDailyGaugeUpdate())
	{
		mSpawn = SpawnTileLocation();
		for (const SpawnTileData& Tile : mSpawn)
		{
			SpawnTileType(Tile.TileLocation, Tile.Tile, Tile.Monster);
			// SpawnTileType(Tile.TileLocation, Tile.Tile, Tile.Monster);
		}
	}
}
void UTestStageLevel::MonsterFightCheck()
{
	FVector PlayerLocation = Player->GetActorLocation();
	int PlayerX = static_cast<int>(PlayerLocation.X / 50);
	int PlayerY = static_cast<int>(PlayerLocation.Y / 50);

	for (int i = 0; i < Monsters.size(); ++i)
	{
		if (nullptr == Monsters[i])
		{
			continue;
		}

		Monster = Monsters[i];

		FVector MonsterLocation = Monster->GetActorLocation();
		int MonsterX = static_cast<int>(MonsterLocation.X / 50);
		int MonsterY = static_cast<int>(MonsterLocation.Y / 50);

		if (PlayerX == MonsterX && PlayerY == MonsterY)
		{
			if (fmod(PlayerLocation.X, 50.0f) == 25.0f && fmod(PlayerLocation.Y, 50.0f) == 25.0f && false == IsFight)
			{
				FightCheckMonsters.push_back(Monsters[i]);
			}
		}
	}

	if (0 != FightCheckMonsters.size())
	{
		ChangeState(EStageState::Fight);
	}
}

void UTestStageLevel::Move(float _DeltaTime)
{
	Player->WayPoints(_DeltaTime);

	MonsterSpawnTimeCheck(_DeltaTime);

	MonsterFightCheck();
}

void UTestStageLevel::FightStart()
{
	if (0 >= FightCheckMonsters.size())
	{
		MsgBoxAssert("싸울몬스터가 존재하지 않는데 싸움상태로 들어왔습니다");
		MonsterFights.clear();
	}

	FightZone->SetActorLocation({ 530, 340 });
	FightZone->SetActive(true);

	PlayerFight->SetActorLocation({ 380, 400 });
	PlayerFight->SetActive(true);

	for (size_t i = 0; i < FightCheckMonsters.size(); i++)
	{
		AMonsterFight* MonsterFight = SpawnActor<AMonsterFight>();
		MonsterFight->StatusInit(26, 26, 1, 3, 1, 0.6f, 0, 25, 25, 25, 25);
		MonsterFights.push_back(MonsterFight);
	}

	FVector MonsterPositions[5] = {
	{ 600, 400 },
	{ 600, 300 },
	{ 700, 500 },
	{ 700, 400 },
	{ 700, 300 }
	};

	// 5마리
	for (size_t i = 0; i < MonsterFights.size(); i++)
	{
		AMonsterFight* MonsterFight = MonsterFights[i];
		MonsterFight->SetActorLocation(MonsterPositions[i]);
	}

	FightZone->FightZoneInit(PlayerFight, MonsterFights);
}

void UTestStageLevel::Fight(float _DeltaTime)
{
	FightZone->Battle(_DeltaTime);

	if (true == FightZone->AllMonsterDeath())
	{
		FightZone->SetActive(false);
		PlayerFight->SetActive(false);

		for (size_t i = 0; i < FightCheckMonsters.size(); i++)
		{
			FightCheckMonsters[i]->Destroy();
		}

		for (size_t i = 0; i < MonsterFights.size(); i++)
		{
			MonsterFights[i]->Destroy();
		}

		FightCheckMonsters.clear();
		MonsterFights.clear();

		ChangeState(EStageState::Move);
	}
}

void UTestStageLevel::StateUpdate(float _DeltaTime)
{
	switch (CurState)
	{
	case EStageState::Move:
	{
		Move(_DeltaTime);
		break;
	}
	case EStageState::Fight:
		Fight(_DeltaTime);
		break;
	default:
		break;
	}


}

void UTestStageLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

	// 몬스터가 만들

	//if (false == FightZone->IsBattle)
	//{
	//	StageprogressGauge->StageProgressGaugeUpdate(_DeltaTime);
	//}
	//else
	//{
	//	float FightDailyTime = _DeltaTime / 10;
	//	StageprogressGauge->StageProgressGaugeUpdate(FightDailyTime);
	//}

	//if (UEngineInput::IsDown('P'))
	//{
	//	Player->SetMoveSpeed(500.0f);
	//}

	//if (0 == StageprogressGauge->GetDailyGaugeUpdate())
	//{
	//	mSpawn = SpawnTileLocation();
	//	for (const SpawnTileData& Tile : mSpawn)
	//	{
	//		SpawnTileType(Tile.TileLocation, Tile.Tile, Tile.Monster);
	//	}

	//	for (auto& FightMonster : Monsters)
	//	{
	//		MonsterFight = SpawnActor<AMonsterFight>();
	//		MonsterFight->SetActive(false, 0.1f);
	//		MonsterFight->StatusInit(26, 26, 1, 3, 1, 0.6f, 0, 25, 25, 25, 25);
	//		MonsterFights.push_back(MonsterFight);
	//	}
	//}

	//Fight(Player, _DeltaTime);
}

std::vector<FVector> UTestStageLevel::StagePoints(const std::string& _StageName)
{

	std::vector<FVector> Tutorial =
	{
		{575, 225, 0, 0},
		{625, 225, 0, 0},
		{625, 275, 0, 0},
		{625, 325, 0, 0},
		{625, 375, 0, 0},
		{575, 375, 0, 0},
		{575, 425, 0, 0},
		{525, 425, 0, 0},
		{475, 425, 0, 0},
		{425, 425, 0, 0},
		{425, 375, 0, 0},
		{425, 325, 0, 0},
		{425, 275, 0, 0},
		{475, 275, 0, 0},
		{475, 225, 0, 0},
		{525, 225, 0, 0},
	};

	return Tutorial;
}

void UTestStageLevel::StageMovePlayer(APlayer* _Player)
{
	std::vector<FVector> MovePoint = StagePoints("Tutorial");

	for (const FVector& MovePoints : MovePoint)
	{
		_Player->SetWayPoint(MovePoints);
	}
}

std::vector<FVector> UTestStageLevel::MonsterMovePoints(FVector _Location)
{
	FVector CenterLocation = { (int)(_Location.X / 50) * 50, (int)(_Location.Y / 50) * 50 };

	if (_Location.X == CenterLocation.X + 10 && _Location.Y == CenterLocation.Y + 10)
	{
		return {
			{_Location.X, _Location.Y},
			{_Location.X + 30, _Location.Y},
			{_Location.X + 30, _Location.Y + 30},
			{_Location.X, _Location.Y + 30},
		};
	}

	else if (_Location.X == CenterLocation.X + 40 && _Location.Y == CenterLocation.Y + 10)
	{
		return {
			{_Location.X, _Location.Y},
			{_Location.X, _Location.Y + 30},
			{_Location.X - 30, _Location.Y + 30},
			{_Location.X - 30, _Location.Y},
		};
	}
	else if (_Location.X == CenterLocation.X + 10 && _Location.Y == CenterLocation.Y + 40)
	{
		return {
			{_Location.X, _Location.Y},
			{_Location.X, _Location.Y - 30},
			{_Location.X + 30, _Location.Y - 30},
			{_Location.X + 30, _Location.Y},
		};
	}
	else if (_Location.X == CenterLocation.X + 40 && _Location.Y == CenterLocation.Y + 40)
	{
		return {
			{_Location.X, _Location.Y},
			{_Location.X - 30, _Location.Y },
			{_Location.X - 30, _Location.Y - 30},
			{_Location.X, _Location.Y - 30},
		};
	}
	else
	{
		return {
			{_Location.X, _Location.Y}
		};
	}
}

void UTestStageLevel::StageMoveMonster(AMonster* _Monster, FVector _Location)
{
	std::vector<FVector> MovePoint = MonsterMovePoints(_Location);

	for (const FVector& MovePoints : MovePoint)
	{
		_Monster->SetWayPoint(MovePoints);
	}
}

FVector UTestStageLevel::RandomSpawnLocation(FVector _Location)
{

	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 3);

	int selectedIndex = dis(gen);

	switch (selectedIndex)
	{
	case 0: return _Location;
	case 1: return { _Location.X + 30, _Location.Y };
	case 2: return { _Location.X + 30, _Location.Y + 30 };
	case 3: return { _Location.X, _Location.Y + 30 };
	default: return _Location;
	}
}

std::vector<SpawnTileData> UTestStageLevel::SpawnTileLocation()
{
	std::vector<SpawnTileData> SpawnTile =
	{
		{ RandomSpawnLocation({610, 210, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({610, 260, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({610, 310, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({610, 360, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({560, 360, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({560, 410, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({510, 410, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({460, 410, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({410, 410, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({410, 360, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({410, 310, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({410, 260, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({460, 260, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({460, 210, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
		{ RandomSpawnLocation({510, 210, 0, 0}), TileType::WASTELAND, MonsterType::Slime },
	};

	return SpawnTile;
}

void UTestStageLevel::SpawnTileType(FVector _Location, TileType _TileType, MonsterType _MonsterType)
{
	switch (_TileType)
	{
	case TileType::WASTELAND:
		if (RandomEngine.RandomFloat(0, 1.0) < 0.25)
		{
			MonsterSpawn(_Location, _MonsterType);
			MonsterSpawn(_Location, _MonsterType);
		}
		break;
	case TileType::CEMETERY:
		break;
	case TileType::GROVE:
		break;
	case TileType::BLOODPATH:
		break;
	case TileType::VILLAGE:
		break;
	case TileType::RANSACKEDVILLAGE:
		break;
	case TileType::COUNTSLAND:
		break;
	case TileType::WHEATFIELDS:
		break;
	case TileType::OVERGROWNFIELD:
		break;
	case TileType::RUINS:
		break;
	case TileType::SWAMP:
		break;
	case TileType::AVILLAGE:
		break;
	case TileType::BRIDGE:
		break;
	default:
		break;
	}
}

void UTestStageLevel::MonsterSpawn(FVector _Location, MonsterType _MonsterType)
{
	Monster = SpawnActor<AMonster>();
	Monster->SetActorLocation(_Location);
	Monster->SetMoveSpeed(50.0f);
	StageMoveMonster(Monster, _Location);
	Monsters.push_back(Monster);
}


//void UTestStageLevel::Fight(APlayer* _Player, float _DeltaTime)
// {
	//FVector PlayerLocation = _Player->GetActorLocation();
	//int PlayerX = static_cast<int>(PlayerLocation.X / 50);
	//int PlayerY = static_cast<int>(PlayerLocation.Y / 50);

	//std::vector<FVector> MonsterPositions = {
	//{ 600, 400 },
	//{ 600, 300 },
	//{ 700, 500 },
	//{ 700, 400 },
	//{ 700, 300 }
	//};

	//int MonsterPositionIndex = 0;

	//for (int i = 0; i < Monsters.size(); ++i)
	//{
	//	if (nullptr == Monsters[i])
	//	{
	//		continue;
	//	}

	//	Monster = Monsters[i];
	//	MonsterFight = MonsterFights[i];

	//	FVector MonsterLocation = Monster->GetActorLocation();
	//	int MonsterX = static_cast<int>(MonsterLocation.X / 50);
	//	int MonsterY = static_cast<int>(MonsterLocation.Y / 50);

	//	if (PlayerX == MonsterX && PlayerY == MonsterY)
	//	{
	//		if (fmod(PlayerLocation.X, 50.0f) == 25.0f && fmod(PlayerLocation.Y, 50.0f) == 25.0f && false == IsFight)
	//		{
	//			_Player->IsMove = false;

	//			FightZone->SetActorLocation({ 530, 340 });
	//			FightZone->SetActive(true);

	//			PlayerFight->SetActorLocation({ 380, 400 });
	//			PlayerFight->SetActive(true);

	//			MonsterFight->SetActorLocation(MonsterPositions[MonsterPositionIndex]);
	//			MonsterFight->SetActive(true);
	//			MonsterPositionIndex = (MonsterPositionIndex + 1) % MonsterPositions.size();

	//			if (false == FightZone->IsBattle)
	//			{
	//				FightZone->Battle(PlayerFight, MonsterFights, _DeltaTime);
	//			}
	//			else
	//			{
	//				IsFight = true;
	//			}
	//		}
	//		else
	//		{
	//			_Player->IsMove = true;
	//			IsFight = false;
	//			FightZone->IsBattle = false;
	//			FightZone->SetActive(false, 0.1f);
	//			PlayerFight->SetActive(false, 0.1f);
	//			MonsterFight->SetActive(false, 0.1f);

	//			if (MonsterFight->IsDeath())
	//			{
	//				Monsters[i] = nullptr;
	//				MonsterFights[i] = nullptr;

	//				MonsterFight->Destroy();
	//				Monster->Destroy();
	//			}
	//		}
	//	}
	//}
//}

void UTestStageLevel::SetStageUI()
{
	StageprogressGauge = SpawnActor<StageUI::AStageProgressGauge>();
	StageprogressGauge->SetActorLocation({ 115, 25 });




	SppedPanel = SpawnActor<StageUI::ASpeedPanel>();
	SppedPanel->SetActorLocation({ 308, 25 });

	APlashka = SpawnActor<StageUI::APlashka>();
	APlashka->SetActorLocation({ 533, 25 });

	TravelitemPanel = SpawnActor<StageUI::ATravelitemPanel>();
	TravelitemPanel->SetActorLocation({ 866,25 });
}

void UTestStageLevel::SetEQInventory()
{
	EQInventory = SpawnActor<EQInventory::AEQInventoryUI>();
	EQInventory->SetActorLocation({ 1130, 360 });
}
