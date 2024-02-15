#include "IntroLevel.h"
#include "IntroRender.h"

#include "EngineCore/EngineCore.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>

UIntroLevel::UIntroLevel()
{
}

UIntroLevel::~UIntroLevel()
{
}

void UIntroLevel::BeginPlay()
{
	ULevel::BeginPlay();
	AIntroRender* Intro = SpawnActor<AIntroRender>();
}

void UIntroLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	SkipStage -= _DeltaTime;
	if (SkipStage < 0)
	{
		GEngine->ChangeLevel("TutorialLevel");
	}

}
