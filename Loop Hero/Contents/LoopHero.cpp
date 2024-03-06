#include "LoopHero.h"
#include "Level.h"

#include <EngineBase\EngineDirectory.h>
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

	RecourceLoad();

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UIntroLevel>("IntroLevel");
	CreateLevel<UTestStageLevel>("StageLevel");
	ChangeLevel("StageLevel");
}

void LoopHeroContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}

void LoopHeroContentsCore::End()
{
	UEngineCore::End();
}

void LoopHeroContentsCore::RecourceLoad()
{
	UEngineDirectory RecourceDir;
	RecourceDir.MoveParent();
	RecourceDir.Move("Recource");

	std::list<UEngineFile> RecourceList = RecourceDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : RecourceList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Warrior.png", 5, 8);
	UEngineResourcesManager::GetInst().CuttingImage("Overworld Enemies.png", 4, 12);
	UEngineResourcesManager::GetInst().CuttingImage("Slime.png", 5, 3);
	UEngineResourcesManager::GetInst().CuttingImage("Cards.png", 5, 2);
}

