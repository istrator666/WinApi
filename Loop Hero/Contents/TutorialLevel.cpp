#include "TutorialLevel.h"
#include "TutorialRander.h"

#include "EngineCore/EngineCore.h"

#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>

UTutorialLevel::UTutorialLevel()
{
}

UTutorialLevel::~UTutorialLevel()
{
}

void UTutorialLevel::BeginPlay()
{
	ULevel::BeginPlay();

	UEngineDirectory TutorialDir;
	TutorialDir.MoveParent();
	TutorialDir.Move("Recource");
	TutorialDir.Move("TutorialStage");

	std::list<UEngineFile> TutorialList = TutorialDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : TutorialList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineDirectory PlayerDir;

	PlayerDir.MoveParent();
	PlayerDir.Move("Recource");
	PlayerDir.Move("Player");

	std::list<UEngineFile> PlayerList = PlayerDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : PlayerList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("WarriorPlayer.png", 5, 8);
	UEngineResourcesManager::GetInst().CuttingImage("001.png", 5, 8);

	ATutorialRander* Tutorial = SpawnActor<ATutorialRander>();
}

void UTutorialLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	//if (UEngineInput::IsDown('P'))
	//{
	//	GEngine->ChangeLevel("Player");
	//}

}