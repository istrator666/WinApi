#include "UnitStatus.h"

UnitStatus::UnitStatus()
{
}

UnitStatus::~UnitStatus()
{
}

void UnitStatus::StatusInit(int _HP, int _MinAttck, int _MaxAttck, int _Defense, float _Speed, int _AttckSpeed, int _HPRegen, int _Critical, int _CounterAttack, int _LifeDrain)
{
	SetHP(_HP);
	SetMinAttck(_MinAttck);
	SetMaxAttck(_MaxAttck);
	SetDefense(_Defense);
	SetSpeed(_Speed);
	SetAttckSpeed(_AttckSpeed);
	SetHPRegen(_HPRegen);
	SetCritical(_Critical);
	SetCounterAttack(_CounterAttack);
	SetLifeDrain(_LifeDrain);
}
