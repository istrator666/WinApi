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

	UEngineDirectory TitleDir;
	TitleDir.MoveParent();
	TitleDir.Move("Recource");
	TitleDir.Move("Title");

	std::list<UEngineFile> TitleList = TitleDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : TitleList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineDirectory ButtonDir;
	ButtonDir.MoveParent();
	ButtonDir.Move("Recource");
	ButtonDir.Move("Button");

	std::list<UEngineFile> ButtonList = ButtonDir.AllFile({ ".png", ".bmp" }, true);
	for (UEngineFile& File : ButtonList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	ATitleRender* Title = SpawnActor<ATitleRender>();
}

void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("TutorialLevel");
	}

}
