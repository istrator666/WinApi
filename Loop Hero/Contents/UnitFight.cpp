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

void UnitFight::AttDamege(UnitFight& _Unit)
{
	int HP = GetHP();
    HP -= _Unit.GetRandomAtt();
    SetHP(HP);
}

bool UnitFight::AttSpeed(UnitFight& _Unit, float _DeltaTime)
{
    float Speed = GetSpeed();
    Speed += 100 * (_DeltaTime / 2.0f);
    SetSpeed(Speed);

    if (100 <= Speed)
    {
        SetSpeed(0);

        return true;
    }

    return false;
}
