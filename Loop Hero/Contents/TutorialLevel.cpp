#include "TutorialLevel.h"
#include "StageMap.h"
#include "Player.h"

#include "EngineCore/EngineCore.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>


UTutorialLevel::UTutorialLevel()
{
}

UTutorialLevel::~UTutorialLevel()
{
}

void UTutorialLevel::BeginPlay()
{
	ULevel::BeginPlay();

	AStageMap* Stage = SpawnActor<AStageMap>();
	Stage->SetMapImage("StageBackGround.png", "TutorialStage01.png", "BaseCamp01.png");

	APlayer* Player = SpawnActor<APlayer>();

}

void UTutorialLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}