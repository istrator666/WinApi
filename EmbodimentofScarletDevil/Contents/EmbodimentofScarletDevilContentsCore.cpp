#include "EmbodimentofScarletDevilContentsCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

EmbodimentofScarletDevilContentsCore::EmbodimentofScarletDevilContentsCore()
	: UEngineCore()
{
}

EmbodimentofScarletDevilContentsCore::~EmbodimentofScarletDevilContentsCore()
{
}

void EmbodimentofScarletDevilContentsCore::BeginPlay()
{
	MainWindow.SetWindowScale({1280, 720});
	UEngineCore::BeginPlay();
	SetFrame(60);

	UEngineDirectory NewDir;
	NewDir.MoveParent();
	NewDir.Move("Recource");
	NewDir.Move("Title Screen and Menus");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	CreateLevel<UTitleLevel>("TitleLevel");

	ChangeLevel("TitleLevel");
}

void EmbodimentofScarletDevilContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}

void EmbodimentofScarletDevilContentsCore::End()
{
}