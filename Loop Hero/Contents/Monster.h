#pragma once
#include "UnitFight.h"
#include <list>
#include "Enum.h"

class AMonster : public UnitFight
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

	void SetMonsterImage();
	void SetWayPoint(FVector _WayPoint);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void WayPoints(float _DeltaTime);

	UImageRenderer* MonsterRender = nullptr;

	std::list<FVector> WayPoint;
	std::list<FVector>::iterator CurrentWayPoint;

	float MoveSpeed = GetMoveSpeed();
};

class AMonsterFight : public UnitFight
{
public:
	// constrcuter destructer
	AMonsterFight();
	~AMonsterFight();

	// delete Function
	AMonsterFight(const AMonsterFight& _Other) = delete;
	AMonsterFight(AMonsterFight&& _Other) noexcept = delete;
	AMonsterFight& operator=(const AMonsterFight& _Other) = delete;
	AMonsterFight& operator=(AMonsterFight&& _Other) noexcept = delete;

	void SetMosnterFightImage();
	void SetMonsterHealthBar();
	void SetMonsterHPbar(int _Damage);
	void SetChangeAnimation(CharacterStatus _Status);
	bool IsAnimationPlaying();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MonsterFightRender = nullptr;
	UImageRenderer* MonsterHealthBar = nullptr;
	UImageRenderer* MonsterHPBar = nullptr;
	UImageRenderer* MonsterAttSpeedBar = nullptr;

};
