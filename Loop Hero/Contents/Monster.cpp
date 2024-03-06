#include "Monster.h"

AMonster::AMonster()
{
}

AMonster::~AMonster()
{
}

void AMonster::BeginPlay()
{
	AActor::BeginPlay();
	SetMonsterImage();
}

void AMonster::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	WayPoints(_DeltaTime, IsMove);
}

void AMonster::SetMonsterImage()
{
	MonsterRender = CreateImageRenderer();
	MonsterRender->SetImage("Overworld Enemies.png");
	MonsterRender->SetOrder(4);
	MonsterRender->SetTransform({ {0,0}, {250,250} });
	MonsterRender->CreateAnimation("Idle", "Overworld Enemies.png", 38, 39, 0.3f, true);
	MonsterRender->ChangeAnimation("Idle");
}

void AMonster::SetWayPoint(FVector _WayPoint)
{
	WayPoint.push_back(_WayPoint);

	CurrentWayPoint = WayPoint.begin();
}

void AMonster::WayPoints(float _DeltaTime, bool _IsMove)
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

AMonsterFight::AMonsterFight()
{
}

AMonsterFight::~AMonsterFight()
{
}

void AMonsterFight::BeginPlay()
{
	AActor::BeginPlay();
	SetMosnterFightImage();
	SetMonsterHealthBar();
}

void AMonsterFight::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AMonsterFight::SetMosnterFightImage()
{
	MonsterFightRender = CreateImageRenderer();
	MonsterFightRender->SetImage("Slime.png");
	MonsterFightRender->SetOrder(7);
	MonsterFightRender->SetTransform({ {0,0}, {250,250} });
	MonsterFightRender->CreateAnimation("Idle", "Slime.png", 0, 0, 0.1f, false);
	MonsterFightRender->CreateAnimation("Attack", "Slime.png", 1, 5, 0.1f, false);
	MonsterFightRender->CreateAnimation("Hurt", "Slime.png", 6, 9, 0.25f, false);
	MonsterFightRender->CreateAnimation("Death", "Slime.png", 10, 14, 0.25f, false);
	MonsterFightRender->ChangeAnimation("Idle");
}

void AMonsterFight::SetMonsterHealthBar()
{
	MonsterHealthBar = CreateImageRenderer();
	MonsterHealthBar->SetImage("s_healthbar_0.png");
	MonsterHealthBar->SetOrder(7);
	MonsterHealthBar->SetTransform({ {0,-50}, {80,20} });

	MonsterHPBar = CreateImageRenderer();
	MonsterHPBar->SetImage("s_healthbar_1.png");
	MonsterHPBar->SetSortType(EImageSortType::Left);
	MonsterHPBar->SetOrder(8);
	MonsterHPBar->SetTransform({ {-26, -51}, {52,20} });

	MonsterAttackGaugeBar = CreateImageRenderer();
	MonsterAttackGaugeBar->SetImage("s_healthbar_2.png");
	MonsterAttackGaugeBar->SetSortType(EImageSortType::Left);
	MonsterAttackGaugeBar->SetOrder(8);
	MonsterAttackGaugeBar->SetTransform({ {-26, -48}, {52,20} });
}

void AMonsterFight::SetMonsterHPbar(int _CurrentHP)
{
	MonsterHPBar->SetTransform({ {-26, -51}, {_CurrentHP, 20} });
}

void AMonsterFight::SetPlyerAttackGaugeBar(int _AttackTime)
{
	MonsterAttackGaugeBar->SetTransform({ {-26, -48}, {_AttackTime, 20} });
}


void AMonsterFight::SetChangeAnimation(CharacterStatus _Status)
{
	switch (_Status)
	{
	case CharacterStatus::Idle:
		MonsterFightRender->ChangeAnimation("Idle");
		break;
	case CharacterStatus::Attack:
		MonsterFightRender->ChangeAnimation("Attack");
		break;
	case CharacterStatus::Hurt:
		MonsterFightRender->ChangeAnimation("Hurt");
		break;
	case CharacterStatus::Death:
		MonsterFightRender->ChangeAnimation("Death");
		break;
	default:
		break;
	}
}

bool AMonsterFight::IsAnimationEnd()
{
	if (MonsterFightRender->IsCurAnimationEnd())
	{
		return true;
	}

	return false;
}

std::string AMonsterFight::GetCurrentAnimationName()
{
	std::string CurAnimation = MonsterFightRender->GetCurAnimation()->Name;

	return CurAnimation;
}