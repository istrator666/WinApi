#include "TestStageLevel.h"
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

	InitTileMap();

	Stage = SpawnActor<AStageMap>();
	Stage->SetActorLocation({25, 25});

	Player = SpawnActor<APlayer>();
	Player->SetActorLocation({ 575, 225 });
	StageMovePlayer(Player);

	SetStageUI();
	SetEQInventory();

	FightZone = SpawnActor<AFightZone>();
	FightZone->SetActive(false);

	PlayerFight = SpawnActor<APlayerFight>();
	PlayerFight->SetActive(false);

	CardInventory = SpawnActor<ACardInventory>();
	CardInventory->SetActorLocation({ 40, 0 });

}

void UTestStageLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);
	GamePause();

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
	case EStageState::Pause:

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
		for (SpawnTileData& Tile : mSpawn)
		{
			SpawnTileType(Tile);
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
			if (fmod(PlayerLocation.X, 50.0f) == 25.0f && fmod(PlayerLocation.Y, 50.0f) == 25.0f)
			{
				FightCheckMonsters.push_back(Monsters[i]);
			}
		}
	}

	if (0 != FightCheckMonsters.size())
	{
		//ChangeState(EStageState::Fight);
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
		MonsterFight->StatusInit(26, 26, 1, 3, 1, 1.5f, 0, 25, 25, 25, 25);
		MonsterFights.push_back(MonsterFight);
	}

	FVector MonsterPositions[5] = 
	{
		{ 600, 400 },
		{ 600, 300 },
		{ 700, 500 },
		{ 700, 400 },
		{ 700, 300 }
	};

	for (size_t i = 0; i < MonsterFights.size(); i++)
	{
		AMonsterFight* MonsterFight = MonsterFights[i];
		MonsterFight->SetMosnterFightImage(GetMonsterType());
		MonsterFight->SetActorLocation(MonsterPositions[i]);
	}

	FightZone->FightZoneInit(PlayerFight, MonsterFights);
}

void UTestStageLevel::Fight(float _DeltaTime)
{
	IsFight = true;
	MonsterSpawnTimeCheck(_DeltaTime / 5);
	FightZone->Battle(_DeltaTime);
	FightEnd();
}

void UTestStageLevel::FightEnd()
{
	if (true == FightZone->AllMonsterDeath())
	{
		FightZone->SetActive(false);
		PlayerFight->SetActive(false);


		for (size_t i = 0; i < FightCheckMonsters.size(); i++)
		{
			//CoordinateKey MonsterLocation;
			//MonsterLocation.X = static_cast<int> (FightCheckMonsters[i]->GetActorLocation().X / 50);
			//MonsterLocation.Y = static_cast<int> (FightCheckMonsters[i]->GetActorLocation().Y / 50);
			//--MonsterCounts[MonsterLocation.Key];

			FightCheckMonsters[i]->Destroy();
		}

		for (size_t i = 0; i < MonsterFights.size(); i++)
		{
			MonsterFights[i]->Destroy();
		}

		FightCheckMonsters.clear();
		MonsterFights.clear();

		IsFight = false;
		ChangeState(EStageState::Move);
	}
}

MonsterType UTestStageLevel::GetMonsterType()
{
	return MonsterType();
}

void UTestStageLevel::GamePause()
{
	if (UEngineInput::IsDown(VK_RBUTTON) && false == IsGamePause)
	{
		if (true == IsFight)
		{
			return;
		}
		else
		{
			IsGamePause = true;
			ChangeState(EStageState::Pause);
		}
	}
	else if (UEngineInput::IsDown(VK_RBUTTON) && true == IsGamePause)
	{
		IsGamePause = false;
		ChangeState(EStageState::Move);
	}
}

void UTestStageLevel::MonsterDrop(FVector _MonsterPosition)
{
	int Card = RandomEngine.RandomInt(0, 2);
	CardInventory->AddCard(Card, _MonsterPosition);
}

void UTestStageLevel::InitTileMap()
{
	for (int y = 0; y < TileInfo::Rows; ++y)
	{
		for (int x = 0; x < TileInfo::Cols; ++x)
		{
			TileMap[CoordinateKey(x, y).Key] = 0;
		}
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

	case EStageState::Pause:

		break;
	default:
		break;
	}
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
	int selectedIndex = RandomEngine.RandomInt(0, 3);

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
	SpawnTile =
	{
		{ {575, 225}, RandomSpawnLocation({610, 210, 0, 0}), TileType::WASTELAND },
		{ {625, 225}, RandomSpawnLocation({610, 260, 0, 0}), TileType::WASTELAND },
		{ {625, 275}, RandomSpawnLocation({610, 310, 0, 0}), TileType::WASTELAND },
		{ {625, 325}, RandomSpawnLocation({610, 360, 0, 0}), TileType::WASTELAND },
		{ {625, 375}, RandomSpawnLocation({560, 360, 0, 0}), TileType::WASTELAND },
		{ {575, 375}, RandomSpawnLocation({560, 410, 0, 0}), TileType::WASTELAND },
		{ {575, 425}, RandomSpawnLocation({510, 410, 0, 0}), TileType::WASTELAND },
		{ {525, 425}, RandomSpawnLocation({460, 410, 0, 0}), TileType::WASTELAND },
		{ {475, 425}, RandomSpawnLocation({410, 410, 0, 0}), TileType::WASTELAND },
		{ {425, 425}, RandomSpawnLocation({410, 360, 0, 0}), TileType::WASTELAND },
		{ {425, 375}, RandomSpawnLocation({410, 310, 0, 0}), TileType::WASTELAND },
		{ {425, 325}, RandomSpawnLocation({410, 260, 0, 0}), TileType::WASTELAND },
		{ {425, 275}, RandomSpawnLocation({460, 260, 0, 0}), TileType::WASTELAND },
		{ {475, 275}, RandomSpawnLocation({460, 210, 0, 0}), TileType::WASTELAND },
		{ {525, 225}, RandomSpawnLocation({510, 210, 0, 0}), TileType::WASTELAND },
	};

	return SpawnTile;
}

void UTestStageLevel::SpawnTileType(SpawnTileData& _TileData)
{
	switch (_TileData.Tile)
	{
	case TileType::WASTELAND:
		if (RandomEngine.RandomFloat(0, 1.0) < 1.0)
		{
			MonsterSpawn(_TileData, MonsterType::Slime);
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

void UTestStageLevel::MonsterSpawn(SpawnTileData& _TileData, MonsterType _MonsterType)
{
	//CoordinateKey mMonsterCount;
	//mMonsterCount.X = static_cast<int> (_TileData.TileLocation.X / 50);
	//mMonsterCount.Y = static_cast<int> (_TileData.TileLocation.Y / 50);
	//MonsterCounts[mMonsterCount.Key];

	//if (MonsterCounts[mMonsterCount.Key] > 5)
	//{
	//	return;
	//}

	Monster = SpawnActor<AMonster>();
	Monster->SetMonsterImage(_MonsterType);
	Monster->SetActorLocation(_TileData.SpawnLocation);
	Monster->SetMoveSpeed(50.0f);
	StageMoveMonster(Monster, _TileData.SpawnLocation);
	Monsters.push_back(Monster);

	//++MonsterCounts[mMonsterCount.Key];
}

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
