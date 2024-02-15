#include "TitleLevel.h"
#include "TitleRender.h"

#include "EngineCore/EngineCore.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();
	ATitleRender* Title = SpawnActor<ATitleRender>();
}

void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("IntroLevel");
	}

}
