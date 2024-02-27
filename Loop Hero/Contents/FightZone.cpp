#include "FightZone.h"

AFightZone::AFightZone()
{
}

AFightZone::~AFightZone()
{
}

void AFightZone::BeginPlay()
{
	AActor::BeginPlay();
	FightZoneImage();
}

void AFightZone::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void AFightZone::FightZoneImage()
{
	FightZoneRender = CreateImageRenderer();
	FightZoneRender->SetImage("s_fight_window.png");
	FightZoneRender->SetOrder(6);
	FightZoneRender->SetTransform({ {0, 0}, {620,500} });

}

void AFightZone::SetPlayer(APlayerFight* _Player)
{
	Player = _Player;
}

void AFightZone::SetMonster(AMonsterFight* _Monster)
{
	Monster = _Monster;
}

void AFightZone::Battle(float _DeltaTime)
{
	if (Player != nullptr && Monster != nullptr)
	{
		Player->AttDamege(*Monster, _DeltaTime);
		Monster->AttDamege(*Player, _DeltaTime);
	}
}

