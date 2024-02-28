#pragma once
#include "UnitStatus.h"

class UnitFight : public UnitStatus
{
public:
	// constrcuter destructer
	UnitFight();
	~UnitFight();

	// delete Function
	UnitFight(const UnitFight& _Other) = delete;
	UnitFight(UnitFight&& _Other) noexcept = delete;
	UnitFight& operator=(const UnitFight& _Other) = delete;
	UnitFight& operator=(UnitFight&& _Other) noexcept = delete;

	bool IsDeath();
	int GetRandomAtt();

	void AttDamege(UnitFight& _Unit);
	bool AttSpeed(UnitFight& _Unit, float _DeltaTime);

protected:

private:

};

