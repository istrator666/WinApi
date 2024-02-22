#include "TitleLevel.h"

#include "EngineCore/EngineCore.h"

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	Title = SpawnActor<ATitleRender>();

}

void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_LBUTTON))
	{
		GEngine->ChangeLevel("IntroLevel");
	}

}
