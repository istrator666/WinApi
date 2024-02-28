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

	Monster = SpawnActor<AMonster>();
	Monster->SetActorLocation({ 625, 225 });

	SetStageUI();
	SetEQInventory();

	FightZone = SpawnActor<AFightZone>();
	FightZone->SetActive(false, 0.1f);

	PlayerFight = SpawnActor<APlayerFight>();
	PlayerFight->SetActive(false, 0.1f);

	MonsterFight = SpawnActor<AMonsterFight>();
	MonsterFight->SetActive(false, 0.1f);

}

void UTestStageLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	Fight(Player, Monster, _DeltaTime);
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
		{475, 225, 0, 0},
	};

	return Tutorial;
}

void UTestStageLevel::StageMovePlayer(APlayer* _Player)
{
	std::vector<FVector> MovePoint = StagePoints("Tutorial");

	for (const FVector &MovePoints : MovePoint)
	{
		_Player->SetWayPoint(MovePoints);
	}
}


void UTestStageLevel::Fight(APlayer* _Player, AMonster* _Monster, float _DeltaTime)
{
	FVector PlayerLocation = _Player->GetActorLocation();
	FVector MonsterLocation = _Monster->GetActorLocation();

	int PlayerX = static_cast<int>(PlayerLocation.X / 50);
	int PlayerY = static_cast<int>(PlayerLocation.Y / 50);

	int MonsterX = static_cast<int>(MonsterLocation.X / 50);
	int MonsterY = static_cast<int>(MonsterLocation.Y / 50);

	if (PlayerX == MonsterX && PlayerY == MonsterY)
	{
		if (fmod(PlayerLocation.X, 50.0f) == 25.0f && fmod(PlayerLocation.Y, 50.0f) == 25.0f)
		{
			_Player->IsMove = false;

			FightZone->SetActorLocation({ 530, 340 });
			FightZone->SetActive(true);

			PlayerFight->SetActorLocation({ 380, 400 });
			PlayerFight->SetActive(true);

			MonsterFight->SetActorLocation({600, 400});
			MonsterFight->SetActive(true);

			FightZone->Battle(PlayerFight, MonsterFight, _DeltaTime);
		}
	}
	else
	{
		Player->IsMove = true;
		FightZone->SetActive(false, 0.1f);
		PlayerFight->SetActive(false, 0.1f);
		MonsterFight->SetActive(false, 0.1f);
	}

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
