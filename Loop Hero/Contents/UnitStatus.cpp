#include "UnitStatus.h"

UnitStatus::UnitStatus()
{
}

UnitStatus::~UnitStatus()
{
}

void UnitStatus::StatusInit(int _HP, int _MaxHP, int _MinAttck, int _MaxAttck, int _Defense, float _AttackSpeed, float _AttackTime, int _HPRegen, int _Critical, int _CounterAttack, int _LifeDrain)
{
	SetHP(_HP);
	SetMaxHP(_MaxHP);
	SetMinAttck(_MinAttck);
	SetMaxAttck(_MaxAttck);
	SetDefense(_Defense);
	SetAttackSpeed(_AttackSpeed);
	SetHPRegen(_HPRegen);
	SetCritical(_Critical);
	SetCounterAttack(_CounterAttack);
	SetLifeDrain(_LifeDrain);
}
