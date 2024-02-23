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

	FightZone();
}

void AFightZone::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AFightZone::FightZone()
{
	FightZoneRender = CreateImageRenderer();
	FightZoneRender->SetImage("s_fight_window.png");
	FightZoneRender->SetOrder(6);
	FightZoneRender->SetTransform({ {720, 360}, {300,300} });
}