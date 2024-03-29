#include "TutorialLevel.h"

UTutorialLevel::UTutorialLevel()
{
}

UTutorialLevel::~UTutorialLevel()
{
}

void UTutorialLevel::Talk2Start()
{
	DiaLog->Text01();
}

void UTutorialLevel::Talk3Start()
{
	DiaLog->TutorialGuideArrow02();
}

void UTutorialLevel::Talk4Start()
{
	DiaLog->Text02();
	APlashka->ChangePlashka(1);
}

void UTutorialLevel::TutorialEQGuide()
{
	if (true == EQInventory->TutorialEQSetUPComplete())
	{
		DiaLog->TutorialGuideArrowEnd();
		++TalkCount;
		ChangeState(EStageState::Talk5);
	}

	if (true == EQInventory->TutorialEQSetup())
	{
		DiaLog->RightArrow->SetActive(false);
	}
}

void UTutorialLevel::TutorialCardGuide()
{
	if (true == CardInventory->TutorialCardComplete())
	{
		++TalkCount;
		ChangeState(EStageState::Talk5);
	}

	if (true == CardInventory->TutorialCardSetUp(true))
	{
		DiaLog->RightArrow2->SetActive(false);
	}
}

void UTutorialLevel::TutorialEQCardGuide()
{
	if (true == EQInventory->TutorialEQSetUPComplete())
	{
		++TalkCount;
	}

	if (true == EQInventory->TutorialEQSetup())
	{
		DiaLog->RightArrow->SetActive(false);
	}

	if (5 == TalkCount)
	{
		if (true == CardInventory->TutorialCardComplete())
		{
			TutorialRender->ToggleTilesActiveState(false);
				++TalkCount;
				DiaLog->RightArrow2->SetPosition({ 125, 670 });
				
				TravelitemPanel->SetActive(true);
		}

	}
	else if (6 == TalkCount)
	{
		if (true == CardInventory->TutorialCardComplete())
		{
			TutorialRender->ToggleTilesActiveState(false);
			++TalkCount;
			ChangeState(EStageState::Talk6);
		}
	}
}

void UTutorialLevel::BeginPlay()
{
	ULevel::BeginPlay();
	BackgroundBGM = UEngineSound::SoundPlay("snd_music_tutor.ogg");
	NewDay = UEngineSound::SoundPlay("snd_start_new_day.ogg");
	RetreatSound = UEngineSound::SoundPlay("snd_retreat.ogg");

	BackgroundBGM.Loop();
	BackgroundBGM.Off();
	NewDay.Off();
	RetreatSound.Off();

	TutorialRender = SpawnActor<ATutorialRender>();
	TutorialRender->SetActorLocation({ 25, 25 });

	Mouse = SpawnActor<AMouse>();

	SetStageUI();
	SetEQInventory();

	CardInventory = SpawnActor<ACardInventory>();
	CardInventory->SetActorLocation({ 40, 0 });
	CardInventory->SetTutorialRender(TutorialRender);

	Player = SpawnActor<APlayer>();
	Player->SetActorLocation({ 575, 225 });
	StageMovePlayer(Player);

	DiaLog = SpawnActor<ADiaLog>();
	DiaLog->SetActive(false);

	FightZone = SpawnActor<AFightZone>();
	FightZone->SetActive(false);

	PlayerFight = SpawnActor<APlayerFight>();
	PlayerFight->SetActive(false);

	ChangeState(EStageState::Talk1);
}

void UTutorialLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	PlayerLocation = Player->GetActorLocation();
	BackgroundBGM.On();

	StateUpdate(_DeltaTime);
}

void UTutorialLevel::ChangeState(EStageState _State)
{
	switch (_State)
	{
	case EStageState::Talk1:
	{
		break;
	}
	case EStageState::Talk2:
	{
		Talk2Start();
		break;
	}
	case EStageState::Talk3:
	{
		Talk3Start();
		break;
	}
	case EStageState::Talk4:
	{
		Talk4Start();
		break;
	}
	case EStageState::Talk5:
	{
		break;
	}
	case EStageState::Talk6:
	{
		break;
	}
	case EStageState::TutorialEnd:
	{

		break;
	}
	case EStageState::TutorialEQGuide:
	{
		break;
	}
	case EStageState::TutorialCardGuide:
	{
		break;
	}
	case EStageState::TutorialEQCardGuide:
	{
		break;
	}
	case EStageState::Move:
	{
		break;
	}
	case EStageState::Fight:
	{
		FightStart();
		break;
	}
	case EStageState::Pause:
		break;
	default:
		break;
	}

	CurState = _State;
}

void UTutorialLevel::StateUpdate(float _DeltaTime)
{
	switch (CurState)
	{
	case EStageState::Talk1:
	{
		Talk1(_DeltaTime);
		break;
	}
	case EStageState::Talk2:
	{
		Talk2(_DeltaTime);
		break;
	}
	case EStageState::Talk3:
	{
		Talk3(_DeltaTime);
		break;
	}
	case EStageState::Talk4:
	{
		Talk4(_DeltaTime);
		break;
	}
	case EStageState::Talk5:
	{
		Talk5(_DeltaTime);
		break;
	}
	case EStageState::Talk6:
	{
		Talk6(_DeltaTime);
		break;
	}
	case EStageState::TutorialEnd:
	{
		TutorialEnd();
		break;
	}
	case EStageState::TutorialEQGuide:
	{	
		TutorialEQGuide();
		break;
	}
	case EStageState::TutorialCardGuide:
	{
		TutorialCardGuide();
		break;
	}
	case EStageState::TutorialEQCardGuide:
	{
		TutorialEQCardGuide();
		break;
	}
	case EStageState::Move:
	{
		Move(_DeltaTime);
		break;
	}
	case EStageState::Fight:
		Fight(_DeltaTime);
		break;

	case EStageState::Pause:
		APlashka->ChangePlashka(0);
		break;
	default:
		break;
	}
}

void UTutorialLevel::GamePause()
{
	//if (UEngineInput::IsDown(VK_RBUTTON) || UEngineInput::IsDown(VK_SPACE) && true == IsGamePause)
	//{

	//	IsGamePause = false;
	//	ChangeState(EStageState::Pause);

	//}
	//else if (UEngineInput::IsDown(VK_RBUTTON) || UEngineInput::IsDown(VK_SPACE) && false == IsGamePause)
	//{
	//	IsGamePause = true;
	//	ChangeState(EStageState::Move);
	//}
}

void UTutorialLevel::Move(float _DeltaTime)
{
	if (625 == PlayerLocation.X && 225 == PlayerLocation.Y)
	{
		ChangeState(EStageState::Talk2);
	}
	else if (625 == PlayerLocation.X && 325 == PlayerLocation.Y)
	{
		ChangeState(EStageState::Talk3);
	}
	else if (425 == PlayerLocation.X && 425 == PlayerLocation.Y)
	{
		NewDay.Replay();
		mSpawn = TutorialSpawnTileLocation();
		for (SpawnTileData& Tile : mSpawn)
		{
			SpawnTileType(Tile);
		}
	}
	else if (575 == PlayerLocation.X && 225 == PlayerLocation.Y && true == IsGameEnd)
	{
		ChangeState(EStageState::TutorialEnd);
	}

	Player->WayPoints(_DeltaTime);
	MonsterFightCheck();
	APlashka->ChangePlashka(1);
}

std::vector<FVector> UTutorialLevel::StagePoints(const std::string& _StageName)
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

void UTutorialLevel::StageMovePlayer(APlayer* _Player)
{
	std::vector<FVector> MovePoint = StagePoints("Tutorial");

	for (const FVector& MovePoints : MovePoint)
	{
		_Player->SetWayPoint(MovePoints);
	}
}

void UTutorialLevel::MonsterFightCheck()
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
		ChangeState(EStageState::Fight);
	}
}

void UTutorialLevel::FightStart()
{
	if (false == FightStartCheckTest)
	{
		return;
	}

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

void UTutorialLevel::Fight(float _DeltaTime)
{
	if (625 == PlayerLocation.X && 375 == PlayerLocation.Y && false == IsFight)
	{
		ChangeState(EStageState::Talk4);
	}

	IsFight = true;
	StageprogressGauge->StageProgressGaugeUpdate(_DeltaTime / 5);
	FightZone->Battle(_DeltaTime);

	MonsterType TutorialCheckMonster = GetMonsterType();
	if (TutorialCheckMonster == MonsterType::Ratwolf && true == FightZone->AllMonsterDeath())
	{
		IsTalk6 = true;
		
		if (true == IsTalk6)
		{
			ChangeState(EStageState::Talk6);
			return;
		}
	}

	FightEnd();
}

void UTutorialLevel::FightEnd()
{
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
		Monsters.clear();

		if (true == IsTalk6)
		{
			ChangeState(EStageState::Talk6);
			return;
		}
		else
		{
			ChangeState(EStageState::Move);
		}

		if (true == IsTalk5)
		{
			ChangeState(EStageState::Move);
		}
		else
		{
			ChangeState(EStageState::Talk5);
		}

		IsFight = false;
	}
}

void UTutorialLevel::SetMonsterType(MonsterType _FightMonsterType)
{
	FightMonsterType = _FightMonsterType;
}

MonsterType UTutorialLevel::GetMonsterType()
{
	return FightMonsterType;
}

void UTutorialLevel::MonsterDrop(FVector _MonsterPosition)
{
	//int Card = RandomEngine.RandomInt(0, 2);
	CardInventory->TutorialAddCard(TutorialDrop, _MonsterPosition);
	EQInventory->TutorialAddEQ(_MonsterPosition);
	TutorialDrop++;
}

void UTutorialLevel::Talk1(float _DeltaTime)
{
	TimeCheck -= _DeltaTime;
	if (0 == TalkCount)
	{
		DiaLog->DialogAnimation(_DeltaTime);

		if (0 > TimeCheck)
		{
			++TalkCount;
		}
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 1 == TalkCount)
	{
		DiaLog->StartNextText01();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 2 == TalkCount)
	{
		DiaLog->StartNextText02();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 3 == TalkCount)
	{
		DiaLog->TutorialGuideArrow01();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_RBUTTON) && 4 == TalkCount || UEngineInput::IsDown(VK_SPACE) && 4 == TalkCount)
	{
		DiaLog->TutorialGuideArrowEnd();
		ChangeState(EStageState::Move);
		TalkCount = 0;
	}
}

void UTutorialLevel::Talk2(float _DeltaTime)
{
	if (UEngineInput::IsDown(VK_LBUTTON))
	{
		DiaLog->TextEnd();
		ChangeState(EStageState::Move);
	}
}

void UTutorialLevel::Talk3(float _DeltaTime)
{
	if (0 == TalkCount)
	{
		NewDay.On();
		MonsterSpawnTimeCheck(_DeltaTime);
		++TalkCount;
	}

	if (UEngineInput::IsDown(VK_RBUTTON) || UEngineInput::IsDown(VK_SPACE))
	{
		DiaLog->TutorialGuideArrowEnd();
		TalkCount = 0;
		ChangeState(EStageState::Move);
	}
}

void UTutorialLevel::Talk4(float _DeltaTime)
{
	if (UEngineInput::IsDown(VK_LBUTTON) && 0 == TalkCount)
	{
		DiaLog->Text02();
		DiaLog->DialogText->SetText("살아있는 슬라임 한 마리군. 꽤나 골칫거리인걸. 이놈들은 뭐든지 소화시켜버리니까.");
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 1 == TalkCount)
	{
		DiaLog->DialogText->SetText("어! 이 생물이 기억났어! 어쩌면 내 기억을 되살리면 모든 게 정상으로 돌아갈지도 몰라");
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 2 == TalkCount)
	{
		DiaLog->TextEnd();
		DiaLog->TutorialGuideArrow03();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 3 == TalkCount)
	{
		DiaLog->TutorialGuideArrowEnd();
		TalkCount = 0;

		//IsFight = true;
		FightStartCheckTest = false;

		ChangeState(EStageState::Fight);
	}

}

void UTutorialLevel::Talk5(float _DeltaTime)
{
	FightStartCheckTest = true;

	if (0 == TalkCount)
	{
		DiaLog->Text03();

		if (UEngineInput::IsDown(VK_LBUTTON))
		{
			++TalkCount;
		}
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 1 == TalkCount)
	{
		DiaLog->TextEnd();
		DiaLog->TutorialGuideArrow04();
		ChangeState(EStageState::TutorialEQGuide);
	}
	else if (2 == TalkCount)
	{
		DiaLog->Text04();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 3 == TalkCount)
	{
		DiaLog->TextEnd();
		DiaLog->TutorialGuideArrow05();
		ChangeState(EStageState::TutorialCardGuide);
	}
	else if (4 == TalkCount)
	{
		DiaLog->TutorialGuideArrow06();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 5 == TalkCount)
	{
		DiaLog->TutorialGuideArrowEnd();
		TalkCount = 0;
		IsTalk5 = true;
		ChangeState(EStageState::Move);
	}
}

void UTutorialLevel::Talk6(float _DeltaTime)
{
	// FightEnd에서 이어서 할 수 있게 생각하기
	// 그 후에 대화 관련 추가하기
	//IsTalk6 = false;

	if (0 == TalkCount)
	{
		DiaLog->Text05();

		if (UEngineInput::IsDown(VK_LBUTTON))
		{
			++TalkCount;
		}
	}
	else if (1 == TalkCount)
	{
		DiaLog->Text06();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 2 == TalkCount)
	{
		DiaLog->Text07();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 3 == TalkCount)
	{
		DiaLog->TextEnd();
		FightEnd();
		DiaLog->TutorialGuideArrow07();
		++TalkCount;
	}
	else if (4 == TalkCount)
	{
		ChangeState(EStageState::TutorialEQCardGuide);
	}
	else if (7 == TalkCount)
	{
		DiaLog->TutorialGuideArrowEnd();
		DiaLog->Text08();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_LBUTTON) && 8 == TalkCount)
	{
		DiaLog->TextEnd();
		DiaLog->TutorialGuideArrow08();
		++TalkCount;
	}
	else if (UEngineInput::IsDown(VK_RBUTTON) && 9 == TalkCount || UEngineInput::IsDown(VK_SPACE) && 9 == TalkCount)
	{
		DiaLog->TutorialGuideArrowEnd();
		ChangeState(EStageState::Move);
		TalkCount = 0;
		IsGameEnd = true;
	}
}

void UTutorialLevel::TutorialEnd()
{
	NewDay.Replay();
	if (0 == TalkCount)
	{
		DiaLog->Text09();

		if (UEngineInput::IsDown(VK_LBUTTON))
		{
			++TalkCount;
		}
	}
	else if (1 == TalkCount)
	{
		APlashka->ChangePlashka(0);
		DiaLog->TextEnd();
		EQInventory->Retreat();
		DiaLog->TutorialGuideArrow09();
		++TalkCount;
	}
	else if (2 == TalkCount)
	{
		if (
			990 <= GEngine->MainWindow.GetMousePosition().X && 1050 >= GEngine->MainWindow.GetMousePosition().X \
			&& 650 <= GEngine->MainWindow.GetMousePosition().Y && 825 >= GEngine->MainWindow.GetMousePosition().Y \
			&& UEngineInput::IsDown(VK_LBUTTON)
			)
		{
			GEngine->ChangeLevel("GameEnd");
			BackgroundBGM.Off();
			RetreatSound.On();
		}
	}
}

std::vector<SpawnTileData> UTutorialLevel::SpawnTileLocation()
{
	SpawnTile =
	{ 
		{ {625, 325}, RandomSpawnLocation({610, 360, 0, 0}), TileType::WASTELAND },
	};

	return SpawnTile;
}

FVector UTutorialLevel::RandomSpawnLocation(FVector _Location)
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

void UTutorialLevel::SpawnTileType(SpawnTileData& _TileData)
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
		if (RandomEngine.RandomFloat(0, 1.0) < 1.0)
		{
			MonsterSpawn(_TileData, MonsterType::Ratwolf);
		}
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

void UTutorialLevel::MonsterSpawn(SpawnTileData& _TileData, MonsterType _MonsterType)
{
	Monster = SpawnActor<AMonster>();
	Monster->SetMonsterImage(_MonsterType);
	Monster->SetActorLocation(_TileData.SpawnLocation);
	SetMonsterType(_MonsterType);
	Monster->SetMoveSpeed(50.0f);
	StageMoveMonster(Monster, _TileData.SpawnLocation);
	Monsters.push_back(Monster);
}

std::vector<SpawnTileData> UTutorialLevel::TutorialSpawnTileLocation()
{
	SpawnTile =
	{
		{ {425, 375}, RandomSpawnLocation({410, 310, 0, 0}), TileType::GROVE },
	};

	return SpawnTile;
}

void UTutorialLevel::MonsterSpawnTimeCheck(float _DeltaTime)
{
	if (0 == StageprogressGauge->GetDailyGaugeUpdate())
	{
		mSpawn = SpawnTileLocation();
		for (SpawnTileData& Tile : mSpawn)
		{
			SpawnTileType(Tile);
		}
	}
}

std::vector<FVector> UTutorialLevel::MonsterMovePoints(FVector _Location)
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

void UTutorialLevel::StageMoveMonster(AMonster* _Monster, FVector _Location)
{
	std::vector<FVector> MovePoint = MonsterMovePoints(_Location);

	for (const FVector& MovePoints : MovePoint)
	{
		_Monster->SetWayPoint(MovePoints);
	}
}


void UTutorialLevel::SetStageUI()
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

void UTutorialLevel::SetEQInventory()
{
	EQInventory = SpawnActor<EQInventory::AEQInventoryUI>();
	EQInventory->SetActorLocation({ 0, 0 });
}
