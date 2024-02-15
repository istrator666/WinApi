#include "Player.h"

APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	AActor::BeginPlay();
	SetActorLocation({ 640, 360 });
	PlayerRender();
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void APlayer::PlayerRender()
{
	UImageRenderer* Player = CreateImageRenderer();
	Player->SetImage("WarriorPlayer.png");
	Player->SetTransform({ {50,-100}, {100, 100} });
	Player->CreateAnimation("Idle", "WarriorPlayer.png", 0, 0, 0.3f, true);
	Player->ChangeAnimation("Idle");
}

