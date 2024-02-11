#include "LoopHero.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

LoopHeroContentsCore::LoopHeroContentsCore()
	: UEngineCore()
{
}

LoopHeroContentsCore::~LoopHeroContentsCore()
{
}

void LoopHeroContentsCore::BeginPlay()
{
	MainWindow.SetWindowScale({1280, 720});
	MainWindow.SetWindowPosition({ 600, 300 });
	UEngineCore::BeginPlay();
	SetFrame(60);

	TitleFileSetup();

	CreateLevel<UTitleLevel>("TitleLevel");

	ChangeLevel("TitleLevel");

}

void LoopHeroContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}

void LoopHeroContentsCore::End()
{
}

void LoopHeroContentsCore::TitleFileSetup()
{
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
}
