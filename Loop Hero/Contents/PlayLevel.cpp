#include "PlayLevel.h"
#include "PlayerRender.h"

#include "EngineCore/EngineCore.h"

#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>

UPlayLevel::UPlayLevel()
{

}

UPlayLevel::~UPlayLevel()
{

}

void UPlayLevel::BeginPlay()
{
	ULevel::BeginPlay();

	UEngineDirectory PlayerDir;

	PlayerDir.MoveParent();
	PlayerDir.Move("Recource");
	PlayerDir.Move("Player");

	std::list<UEngineFile> AllFileList = PlayerDir.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : AllFileList)
	{
		std::string FullPath = File.GetFullPath();

		UEngineResourcesManager::GetInst().LoadImg(FullPath);
	}

	APlayerRender* Player = SpawnActor<APlayerRender>();
}

void UPlayLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}