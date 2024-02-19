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
	SetMonsterImage(LoopHeroRenderOrder::MONSTER);
}

void AMonster::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void AMonster::SetMonsterImage(LoopHeroRenderOrder _Monster)
{
	MonsterRender = CreateImageRenderer();
	MonsterRender->SetImage("Overworld Enemies.png");
	MonsterRender->SetTransform({ {690, 260}, {250,250} });
	MonsterRender->CreateAnimation("Idle", "Overworld Enemies.png", 38, 39, 0.3f, true);
	MonsterRender->ChangeAnimation("Idle");
}

void AMonster::SetWayPoint(FVector _WayPoint)
{
	WayPoint.push_back(_WayPoint);

	CurrentWayPoint = WayPoint.begin();
}

void AMonster::WayPoints(float _DeltaTime)
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