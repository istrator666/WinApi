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
	SetPlayerHealthBar();
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
	PlayerFightRender->CreateAnimation("Idle", "Warrior.png", 17, 17, 0.3f, false);
	PlayerFightRender->CreateAnimation("Attack", "Warrior.png", 18, 22, 0.3f, false);
	PlayerFightRender->CreateAnimation("Hurt", "Warrior.png", 23, 26, 0.3f, false);
	PlayerFightRender->CreateAnimation("Death", "Warrior.png", 27, 31, 0.3f, false);
	PlayerFightRender->ChangeAnimation("Idle");

}

void APlayerFight::SetPlayerHealthBar()
{
	PlayerHealthBar = CreateImageRenderer();
	PlayerHealthBar->SetImage("s_healthbar_0.png");
	PlayerHealthBar->SetOrder(7);
	PlayerHealthBar->SetTransform({ {0, -50}, {80,20} });

	PlayerHPBar = CreateImageRenderer();
	PlayerHPBar->SetImage("s_healthbar_1.png");
	PlayerHPBar->SetOrder(8);
	PlayerHPBar->SetTransform({ {0, -51}, {52,20} });

	PlayerAttSpeedBar = CreateImageRenderer();
	PlayerAttSpeedBar->SetImage("s_healthbar_2.png");
	PlayerAttSpeedBar->SetOrder(8);
	PlayerAttSpeedBar->SetTransform({ {0, -48}, {52,20} });

	PlayerStaminaBar = CreateImageRenderer();
	PlayerStaminaBar->SetImage("s_healthbar_3.png");
	PlayerStaminaBar->SetOrder(8);
	PlayerStaminaBar->SetTransform({ {0, -47}, {52, 15} });
}

void APlayerFight::SetChangeAnimation(CharacterStatus _Status)
{
	switch (_Status)
	{
	case CharacterStatus::Idle:
		PlayerFightRender->ChangeAnimation("Idle");
		break;
	case CharacterStatus::Attack:
		PlayerFightRender->ChangeAnimation("Attack");
		break;
	case CharacterStatus::Hurt:
		PlayerFightRender->ChangeAnimation("Hurt");
		break;
	case CharacterStatus::Death:
		PlayerFightRender->ChangeAnimation("Death");
		break;
	default:
		break;
	}
}

bool APlayerFight::IsAnimationPlaying()
{
	if (PlayerFightRender->IsCurAnimationEnd())
	{
		return true;
	}

	return false;
}

