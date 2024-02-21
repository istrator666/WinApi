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

	APlayer* Player = SpawnActor<APlayer>();
	StageMovePlayer(Player);
	
	AMonster* Monster = SpawnActor<AMonster>();

	AEQInventory* EQInventory = SpawnActor<AEQInventory>();
	AStageUI* StageUI = SpawnActor<AStageUI>();

}

void UStageLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}

std::vector<FVector> UStageLevel::StagePoints(const std::string& _StageName)
{

	std::vector<FVector> Tutorial =
	{
		{0, 0, 0, 0},
		{50, 0, 0, 0},
		{50, 50, 0, 0},
		{50, 100, 0, 0},
		{50, 150, 0, 0},
		{0, 150, 0, 0},
		{0, 200, 0, 0},
		{-50, 200, 0, 0},
		{-100, 200, 0, 0},
		{-150, 200, 0, 0},
		{-150, 150, 0, 0},
		{-150, 100, 0, 0},
		{-150, 50, 0, 0},
		{-100, 50, 0, 0},
		{-100, 0, 0, 0},
		{-50, 0, 0, 0}
	};

	return Tutorial;
}

void UStageLevel::StageMovePlayer(APlayer* _Player)
{
	std::vector<FVector> MovePoint = StagePoints("Tutorial");

	for (const auto& MovePoints : MovePoint) {
		_Player->SetWayPoint(MovePoints);
	}
}

