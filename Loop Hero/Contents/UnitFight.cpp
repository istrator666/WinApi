#include "UnitFight.h"
#include <random>

UnitFight::UnitFight()
{
}

UnitFight::~UnitFight()
{
}

bool UnitFight::IsDeath()
{
    int HP = GetHP();
    return HP <= 0;
}

int UnitFight::GetRandomAtt(int _MinAtt, int _MaxAtt)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(_MinAtt, _MaxAtt);

    return distr(gen);
}

void UnitFight::AttackDamege(UnitFight& _AttUnit, UnitFight& _DefUnit)
{
	int HP = _DefUnit.GetHP();
    HP -= _DefUnit.GetRandomAtt(_AttUnit.GetMinAttck(), _AttUnit.GetMaxAttck());
    _DefUnit.SetHP(HP);
}

bool UnitFight::AttackSpeed(UnitFight& _Unit, float _DeltaTime)
{
    float AttackSpeed = GetAttackGauge();
    AttackSpeed += 100 * (_DeltaTime / GetAttackSpeed());
    SetAttackGauge(AttackSpeed);

    if (100 <= GetAttackGauge())
    {
        SetAttackGauge(0.0f);

        return true;
    }

    return false;
}
