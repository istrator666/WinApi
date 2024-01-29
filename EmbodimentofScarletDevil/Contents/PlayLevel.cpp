#include "PlayLevel.h"
#include "Player.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>

UPlayLevel::UPlayLevel()
{
}

UPlayLevel::~UPlayLevel()
{
}


void UPlayLevel::BeginPlay()
{

	EngineDirectory NewPath;
	std::list<EngineFile> AllFileList = NewPath.AllFile();
	UEngineResourcesManager::GetInst().LoadImg("AAAA.png");

	this->SpawnActor<Player>();

}