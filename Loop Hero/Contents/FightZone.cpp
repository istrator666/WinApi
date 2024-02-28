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

	float PlayerAttackSpeed = PlayerFight->GetAttackSpeed();
	float MonsterAttackSpeed = MonsterFight->GetAttackSpeed();

	if (true == PlayerFight->AttackSpeed(*PlayerFight, _DeltaTime))
	{
		PlayerFight->SetChangeAnimation(CharacterStatus::Attack);
		PlayerFight->AttackDamege(*MonsterFight);

		if (false == MonsterFight->IsAnimationPlaying())
		{
			MonsterFight->SetChangeAnimation(CharacterStatus::Hurt);
			MonsterFight->SetMonsterHPbar(30);
		}
	}

	if (true == MonsterFight->AttackSpeed(*MonsterFight, _DeltaTime))
	{
		MonsterFight->SetChangeAnimation(CharacterStatus::Attack);
		MonsterFight->AttackDamege(*MonsterFight);
		

		if (false == PlayerFight->IsAnimationPlaying())
		{
			PlayerFight->SetChangeAnimation(CharacterStatus::Hurt);
		}
	}

	if (true == MonsterFight->IsAnimationPlaying())
	{
		MonsterFight->SetChangeAnimation(CharacterStatus::Idle);
	}

	if (true == PlayerFight->IsAnimationPlaying())
	{
		PlayerFight->SetChangeAnimation(CharacterStatus::Idle);
	}

}

