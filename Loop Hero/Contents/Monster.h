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

	void SetMonsterImage(MonsterType _MonsterType);
	void SetWayPoint(FVector _WayPoint);
	bool IsMove = true;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MonsterRender = nullptr;

	void WayPoints(float _DeltaTime, bool _IsMove);

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

	void SetMosnterFightImage(MonsterType _MonsterType);
	void SetMonsterHealthBar();
	void SetMonsterHPbar(int _Damage);
	void SetPlyerAttackGaugeBar(int _AttackTime);
	void SetChangeAnimation(CharacterStatus _Status);
	bool IsAnimationEnd();
	std::string GetCurrentAnimationName();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MonsterFightRender = nullptr;
	UImageRenderer* MonsterHealthBar = nullptr;
	UImageRenderer* MonsterHPBar = nullptr;
	UImageRenderer* MonsterAttackGaugeBar = nullptr;

};
