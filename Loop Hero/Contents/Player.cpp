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

	WayPoints(_DeltaTime, IsMove);
}

void APlayer::SetPlayerImage()
{
	PlayerRender = CreateImageRenderer();
	PlayerRender->SetImage("Warrior.png");
	PlayerRender->SetOrder(5);
	PlayerRender->SetTransform({ {0, 0}, {125,125} });
	PlayerRender->CreateAnimation("Idle", "Warrior.png", 0, 3, 0.3f, true);
	PlayerRender->ChangeAnimation("Idle");
}

void APlayer::SetWayPoint(FVector _WayPoint)
{
	WayPoint.push_back(_WayPoint);

	CurrentWayPoint = WayPoint.begin();

}

void APlayer::WayPoints(float _DeltaTime, bool _IsMove)
{
	float CurMoveSpeed = GetMoveSpeed();
	if (false == _IsMove)
	{
		return;
	}

	if (CurrentWayPoint == WayPoint.end())
	{
		CurrentWayPoint = WayPoint.begin();
	}

	FVector PointValue = *CurrentWayPoint;
	FVector LocationValue = GetActorLocation();

	FVector direction = PointValue - LocationValue;
	float distance = direction.Size2D();

	if (distance < CurMoveSpeed * _DeltaTime)
	{
		SetActorLocation(*CurrentWayPoint);
		++CurrentWayPoint;
	}
	else
	{
		direction.Normalize2D();
		AddActorLocation(direction * CurMoveSpeed * _DeltaTime);
	}

}

APlayerFight::APlayerFight()
{
}

APlayerFight::~APlayerFight()
{
}

void APlayerFight::BeginPlay()
{
	AActor::BeginPlay();
	SetPlayerFightImage();
}

void APlayerFight::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}


void APlayerFight::SetPlayerFightImage()
{
	PlayerFightRender = CreateImageRenderer();
	PlayerFightRender->SetImage("Warrior.png");
	PlayerFightRender->SetOrder(7);
	PlayerFightRender->SetTransform({ {0, 0}, {125,125} });
	PlayerFightRender->CreateAnimation("Idle", "Warrior.png", 17, 17, 0.3f, true);
	PlayerFightRender->ChangeAnimation("Idle");

}
