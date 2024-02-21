#include "Player.h"
#include <EnginePlatform/EngineInput.h>



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

	WayPoints(_DeltaTime);
}

void APlayer::SetPlayerImage()
{
	PlayerRender = CreateImageRenderer();
	PlayerRender->SetImage("WarriorPlayer.png");
	PlayerRender->SetOrder(5);
	PlayerRender->SetTransform({ {575, 225}, {125,125} });
	PlayerRender->CreateAnimation("Idle", "WarriorPlayer.png", 0, 3, 0.3f, true);
	PlayerRender->ChangeAnimation("Idle");
}

void APlayer::SetWayPoint(FVector _WayPoint)
{
	WayPoint.push_back(_WayPoint);

	CurrentWayPoint = WayPoint.begin();
}

void APlayer::WayPoints(float _DeltaTime)
{
	if (CurrentWayPoint == WayPoint.end())
	{
		CurrentWayPoint = WayPoint.begin();
	}

	FVector direction = *CurrentWayPoint - GetActorLocation();
	float distance = direction.Size2D();

	if (distance < MoveSpeed * _DeltaTime)
	{
		SetActorLocation(*CurrentWayPoint);
		++CurrentWayPoint;
	}
	else
	{
		direction.Normalize2D();
		AddActorLocation(direction * MoveSpeed * _DeltaTime);
	}
}