#pragma once
#include <EngineCore/Actor.h>
#include <list>
#include "Enum.h"

class AMonster : public AActor
{
public:
	// constrcuter destructer
	AMonster();
	~AMonster();

	// delete Function
	AMonster(const AMonster& _Other) = delete;
	AMonster(AMonster&& _Other) noexcept = delete;
	AMonster& operator=(const AMonster& _Other) = delete;
	AMonster& operator=(AMonster&& _Other) noexcept = delete;

	void SetMonsterImage(LoopHeroRenderOrder _Monster);
	void SetWayPoint(FVector _WayPoint);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void WayPoints(float _DeltaTime);

	UImageRenderer* MonsterRender = nullptr;

	std::list<FVector> WayPoint;
	std::list<FVector>::iterator CurrentWayPoint;
	float MoveSpeed = 50.0f;
};

