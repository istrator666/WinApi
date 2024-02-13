#include "PlayerRender.h"

APlayerRender::APlayerRender()
{
}

APlayerRender::~APlayerRender()
{
}

void APlayerRender::BeginPlay()
{
	AActor::BeginPlay();
	PlayerRenderer();
}

void APlayerRender::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void APlayerRender::PlayerRenderer()
{
	UImageRenderer* Player = CreateImageRenderer();
	Player->SetImage("WarriorPlayer.png", 4);
}

