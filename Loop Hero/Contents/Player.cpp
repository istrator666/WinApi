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
	SetPlayerImage();
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void APlayer::WayPoints(float _DeltaTime)
{

}

void APlayer::SetPlayerImage()
{
	PlayerRender = CreateImageRenderer();
	PlayerRender->SetImage("WarriorPlayer.png");
	PlayerRender->SetTransform({ {690, 260}, {100,100} });
	PlayerRender->CreateAnimation("Idle", "WarriorPlayer.png", 0, 3, 0.3f, true);
	PlayerRender->ChangeAnimation("Idle");
}

