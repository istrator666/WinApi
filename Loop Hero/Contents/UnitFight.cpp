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

int UnitFight::GetRandomAtt()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(400, 600);

    return distr(gen);
}

void UnitFight::AttackDamege(UnitFight& _Unit)
{
	int HP = GetHP();
    HP -= _Unit.GetRandomAtt();
    SetHP(HP);
}

bool UnitFight::AttackSpeed(UnitFight& _Unit, float _DeltaTime)
{
    float Speed = GetAttackSpeed();
    Speed += 100 * (_DeltaTime / 2.0f);
    SetAttackSpeed(Speed);

    if (100 <= Speed)
    {
        SetAttackSpeed(0);

        return true;
    }

    return false;
}
