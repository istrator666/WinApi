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

void AFightZone::Battle(APlayerFight* _PlayerFight, AMonsterFight* _MonsterFight, float _DeltaTime)
{
	PlayerFight = _PlayerFight;
	MonsterFight = _MonsterFight;

	float PlayerAttackSpeed = PlayerFight->GetSpeed();

	if (true == PlayerFight->AttSpeed(*PlayerFight, _DeltaTime))
	{
		PlayerFight->SetChangeAnimation(CharacterStatus::Attack);
		PlayerFight->AttDamege(*MonsterFight);
	}

	if (PlayerFight->IsAnimationPlay())
	{
		PlayerFight->SetChangeAnimation(CharacterStatus::Idle);
	}


}

