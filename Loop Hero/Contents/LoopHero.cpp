#include "LoopHero.h"
#include "Level.h"

#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EnginePlatform/EngineSound.h>


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

	UEngineSound::SetGlobalVolume(0.3f);

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UIntroLevel>("IntroLevel");
	CreateLevel<UTutorialLevel>("Tutorial");
	CreateLevel<UGameEndLevel>("GameEnd");
	//CreateLevel<UTestStageLevel>("StageLevel");
	ChangeLevel("TitleLevel");
}

void LoopHeroContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown(VK_F2))
	{
		GEngine->EngineDebugSwitch();
	}
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

	std::list<UEngineFile> SoundList = RecourceDir.AllFile({ ".wav", ".mp3", ".ogg"}, true);

	for (UEngineFile& File : SoundList)
	{
		UEngineSound::Load(File.GetFullPath());
	}

	// 플레이어
	UEngineResourcesManager::GetInst().CuttingImage("Warrior.png", 5, 8);

	// 몬스터
	UEngineResourcesManager::GetInst().CuttingImage("Overworld Enemies.png", 4, 12);
	UEngineResourcesManager::GetInst().CuttingImage("Slime.png", 5, 3);
	UEngineResourcesManager::GetInst().CuttingImage("Ratwolf.png", 5, 3);

	// 카드
	UEngineResourcesManager::GetInst().CuttingImage("Cards.png", 5, 2);
	UEngineResourcesManager::GetInst().LoadFolder(RecourceDir.AppendPath("TutorialCard"));

	// 튜토리얼
	UEngineResourcesManager::GetInst().CuttingImage("Up.png", 5, 8);
	UEngineResourcesManager::GetInst().CuttingImage("Down.png", 5, 8);
	UEngineResourcesManager::GetInst().CuttingImage("Right.png", 5, 8);
	UEngineResourcesManager::GetInst().CuttingImage("Left.png", 5, 8);

	// UI
	UEngineResourcesManager::GetInst().CuttingImage("PlashkaMove.png", 5, 4);
	UEngineResourcesManager::GetInst().CuttingImage("PlashkaPause.png", 5, 1);
	UEngineResourcesManager::GetInst().CuttingImage("s_pobeg.png", 5, 2);

	//무기
	UEngineResourcesManager::GetInst().CuttingImage("Weapons.png", 5, 3);

	//타일
	UEngineResourcesManager::GetInst().LoadFolder(RecourceDir.AppendPath("Tiles"));

}

