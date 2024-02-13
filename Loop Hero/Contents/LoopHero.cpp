#include "LoopHero.h"
#include "TitleLevel.h"
//#include "PlayLevel.h"
#include "TutorialLevel.h"


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

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UTutorialLevel>("TutorialLevel");
	//CreateLevel<UPlayLevel>("Player");

	ChangeLevel("TitleLevel");

}

void LoopHeroContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}

void LoopHeroContentsCore::End()
{
}

