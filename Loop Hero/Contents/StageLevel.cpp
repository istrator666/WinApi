#include "StageLevel.h"
#include "StageMap.h"

#include "EngineCore/EngineCore.h"


UStageLevel::UStageLevel()
{
}

UStageLevel::~UStageLevel()
{
}

void UStageLevel::BeginPlay()
{
	ULevel::BeginPlay();

	AStageMap* Stage = SpawnActor<AStageMap>();

	Player = SpawnActor<APlayer>();
	Player->SetActorLocation({ 575, 225 });
	StageMovePlayer(Player);

	Monster = SpawnActor<AMonster>();
	Monster->SetActorLocation({ 525, 425 });

	EQInventory = SpawnActor<AEQInventory>();
	EQInventory->SetActorLocation({ 1130, 360 });

	StageUI = SpawnActor<AStageUI>();

	FightZone = SpawnActor<AFightZone>();
	FightZone->SetActive(false, 0.1f);
}

void UStageLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	Fight(Player, Monster);
}

std::vector<FVector> UStageLevel::StagePoints(const std::string& _StageName)
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

void UStageLevel::StageMovePlayer(APlayer* _Player)
{
	std::vector<FVector> MovePoint = StagePoints("Tutorial");

	for (const FVector &MovePoints : MovePoint)
	{
		_Player->SetWayPoint(MovePoints);
	}
}


void UStageLevel::Fight(APlayer* _Player, AMonster* _Monster)
{
	FVector PlayerLocation = _Player->GetActorLocation();
	FVector MonsterLocation = _Monster->GetActorLocation();

	int PlayerX = static_cast<int>(PlayerLocation.X / 50);
	int PlayerY = static_cast<int>(PlayerLocation.Y / 50);

	int MonsterX = static_cast<int>(MonsterLocation.X / 50);
	int MonsterY = static_cast<int>(MonsterLocation.Y / 50);

	if (PlayerX == MonsterX && PlayerY == MonsterY)
	{
		FightZone->AllRenderersActiveOn();
	}
	else
	{
		FightZone->AllRenderersActiveOff();
	}

}