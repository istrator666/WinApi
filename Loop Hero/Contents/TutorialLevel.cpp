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

	DiaLog = SpawnActor<ADiaLog>();
}

void UTutorialLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
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