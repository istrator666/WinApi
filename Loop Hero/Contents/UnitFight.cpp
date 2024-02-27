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

void UnitFight::AttDamege(UnitFight& _Unit, float _DeltaTime)
{
    int HP = GetHP();
    float Speed = GetSpeed();

    Speed += 100 * (_DeltaTime / 2.0f);
    SetSpeed(Speed);

    if (100 <= Speed)
    {
        HP -= _Unit.GetRandomAtt();
        SetHP(HP);

        if (0 > HP)
        {
            SetHP(0);
        }
        SetSpeed(0);
    }
}
