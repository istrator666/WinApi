#pragma once
#include "UnitStatus.h"
#include <list>
#include"Enum.h"


// Ό³Έν :
class APlayer : public UnitStatus
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void SetPlayerImage();
	void SetWayPoint(FVector _WayPoint);
	bool IsMove = true;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void WayPoints(float _DeltaTime, bool _IsMove);
	UImageRenderer* PlayerRender = nullptr;
	UImageRenderer* PlayerFightRender = nullptr;

	std::list<FVector> WayPoint;
	std::list<FVector>::iterator CurrentWayPoint;

};

class APlayerFight : public UnitStatus
{
public:
	// constrcuter destructer
	APlayerFight();
	~APlayerFight();

	// delete Function
	APlayerFight(const APlayerFight& _Other) = delete;
	APlayerFight(APlayerFight&& _Other) noexcept = delete;
	APlayerFight& operator=(const APlayerFight& _Other) = delete;
	APlayerFight& operator=(APlayerFight&& _Other) noexcept = delete;

	void SetPlayerFightImage();
	void SetPlayerHealthBar();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* PlayerFightRender = nullptr;
	UImageRenderer* PlayerHealthBar = nullptr;
	UImageRenderer* PlayerHPBar = nullptr;
	UImageRenderer* PlayerAttSpeedBar = nullptr;
	UImageRenderer* PlayerStaminaBar = nullptr;

};
