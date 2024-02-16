#include "Player.h"
#include <list>
#include <EnginePlatform/EngineInput.h>

std::list<FVector> WayPoint;
std::list<FVector>::iterator CurrentWayPoint;

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

	WayPoint.push_back(FVector(0, 0, 0, 0));
	WayPoint.push_back(FVector(50, 0, 0, 0));
	WayPoint.push_back(FVector(50, 50, 0, 0));
	WayPoint.push_back(FVector(50, 100, 0, 0));
	WayPoint.push_back(FVector(50, 150, 0, 0));
	WayPoint.push_back(FVector(0, 150, 0, 0));
	WayPoint.push_back(FVector(0, 200, 0, 0));
	WayPoint.push_back(FVector(-50, 200, 0, 0));
	WayPoint.push_back(FVector(-100, 200, 0, 0));
	WayPoint.push_back(FVector(-150, 200, 0, 0));
	WayPoint.push_back(FVector(-150, 150, 0, 0));
	WayPoint.push_back(FVector(-150, 100, 0, 0));
	WayPoint.push_back(FVector(-150, 50, 0, 0));
	WayPoint.push_back(FVector(-100, 50, 0, 0));
	WayPoint.push_back(FVector(-100, 0, 0, 0));
	WayPoint.push_back(FVector(-50, 0, 0, 0));

	CurrentWayPoint = WayPoint.begin();
}

void APlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	WayPoints(_DeltaTime);
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

void APlayer::SetPlayerImage()
{
	PlayerRender = CreateImageRenderer();
	PlayerRender->SetImage("WarriorPlayer.png");
	PlayerRender->SetTransform({ {690, 260}, {100,100} });
	PlayerRender->CreateAnimation("Idle", "WarriorPlayer.png", 0, 3, 0.3f, true);
	PlayerRender->ChangeAnimation("Idle");
}

