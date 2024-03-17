#include "GameEndLevel.h"

UGameEndLevel::UGameEndLevel()
{
}

UGameEndLevel::~UGameEndLevel()
{
}

void UGameEndLevel::BeginPlay()
{
	ULevel::BeginPlay();
	EndImage = SpawnActor<AGameEndRender>();
}

void UGameEndLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}
