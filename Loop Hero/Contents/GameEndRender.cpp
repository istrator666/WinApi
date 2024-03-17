#include "GameEndRender.h"

AGameEndRender::AGameEndRender()
{
}

AGameEndRender::~AGameEndRender()
{
}

void AGameEndRender::BeginPlay()
{
	AActor::BeginPlay();
	GameEndImage = CreateImageRenderer();
	GameEndImage->SetImage("GameEnd.png");
	GameEndImage->SetTransform({ {640, 360}, {1280, 720 } });
}

void AGameEndRender::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
