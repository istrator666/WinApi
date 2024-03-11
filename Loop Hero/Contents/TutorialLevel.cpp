#include "TutorialLevel.h"

UTutorialLevel::UTutorialLevel()
{
}

UTutorialLevel::~UTutorialLevel()
{
}

void UTutorialLevel::BeginPlay()
{
	ULevel::BeginPlay();

	TutorialRender = SpawnActor<ATutorialRender>();
	TutorialRender->SetActorLocation({ 25, 25 });

	SetStageUI();
	SetEQInventory();

	CardInventory = SpawnActor<ACardInventory>();
	CardInventory->SetActorLocation({ 40, 0 });

	Player = SpawnActor<APlayer>();
	Player->SetActorLocation({ 575, 225 });
	StageMovePlayer(Player);

	DiaLog = SpawnActor<ADiaLog>();
}

void UTutorialLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	FVector PlayerLocation = Player->GetActorLocation();

	StateUpdate(_DeltaTime);
	GamePause();

	if (3 == DiaLog->DialogCount)
	{
		DiaLog->AllRenderersActiveOff();
		TutorialRender->TutorialGuideArrow01();
		++DiaLog->DialogCount;
	}

	if (UEngineInput::IsDown(VK_RBUTTON) || UEngineInput::IsDown(VK_SPACE) && IsGamePause)
	{
		IsGamePause = true;
		ChangeState(EStageState::Move);
		TutorialRender->TutorialGuideArrowEnd();
	}

	if (625 == PlayerLocation.X && 275 == PlayerLocation.Y)
	{
		if (IsGamePause)
		{
			DiaLog->Text01();
			IsGamePause = true;
			ChangeState(EStageState::Pause);
		}
	}

}

void UTutorialLevel::ChangeState(EStageState _State)
{
	switch (_State)
	{
	case EStageState::Move:
		break;
	case EStageState::Fight:
		break;
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
	case EStageState::Move:
	{
		Move(_DeltaTime);
		break;
	}
	case EStageState::Fight:
		break;

	case EStageState::Pause:
		break;
	default:
		break;
	}
}

void UTutorialLevel::GamePause()
{
	if (UEngineInput::IsDown(VK_RBUTTON) || UEngineInput::IsDown(VK_SPACE) && true == IsGamePause)
	{

		IsGamePause = false;
		ChangeState(EStageState::Pause);

		//if (true == IsFight)
		//{
		//	return;
		//}
		//else
		//{

		//}
	}
	else if (UEngineInput::IsDown(VK_RBUTTON) || UEngineInput::IsDown(VK_SPACE) && false == IsGamePause)
	{
		IsGamePause = true;
		ChangeState(EStageState::Move);
	}
}

void UTutorialLevel::Move(float _DeltaTime)
{
	DiaLog->AllRenderersActiveOff();
	Player->WayPoints(_DeltaTime);
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
	EQInventory->SetActorLocation({ 1130, 360 });
}