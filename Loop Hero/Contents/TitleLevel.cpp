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

	FVector PosCheck = UMouseFunction::GetMousePos();

	if (UEngineInput::IsDown(VK_LBUTTON))
	{
		if ((550 <= PosCheck.X && 730 >= PosCheck.X) && (340 <= PosCheck.Y && 380 >= PosCheck.Y))
		{
			GEngine->ChangeLevel("IntroLevel");
		}

	}

	if (UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("StageLevel");
	}
}
