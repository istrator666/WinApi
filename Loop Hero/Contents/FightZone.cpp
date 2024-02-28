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

	if (nullptr != PlayerFight && nullptr != MonsterFight)
	{
		float PlayerAttackSpeed = PlayerFight->GetAttackSpeed();
		float MonsterAttackSpeed = MonsterFight->GetAttackSpeed();

		if (true == PlayerFight->AttackSpeed(*PlayerFight, _DeltaTime) && "DEATH" != MonsterFight->GetCurrentAnimation())
		{
			PlayerFight->SetChangeAnimation(CharacterStatus::Attack);
			PlayerFight->AttackDamege(*PlayerFight, *MonsterFight);

			if ("ATTACK" != MonsterFight->GetCurrentAnimation())
			{

				MonsterFight->SetChangeAnimation(CharacterStatus::Hurt);
				MonsterFight->SetMonsterHPbar(30);
			}
		}

		if (true == MonsterFight->AttackSpeed(*MonsterFight, _DeltaTime) && "DEATH" != MonsterFight->GetCurrentAnimation())
		{
			MonsterFight->SetChangeAnimation(CharacterStatus::Attack);
			MonsterFight->AttackDamege(*MonsterFight, *PlayerFight);

			if ("ATTACK" != PlayerFight->GetCurrentAnimation())
			{
				PlayerFight->SetChangeAnimation(CharacterStatus::Hurt);
			}
		}

		if (MonsterFight->IsDeath())
		{
			MonsterFight->SetChangeAnimation(CharacterStatus::Death);
			if (MonsterFight->IsAnimationPlaying())
			{
				IsBattle = true;
				return;
			}
		}

		if (true == MonsterFight->IsAnimationPlaying() && "DEATH" != MonsterFight->GetCurrentAnimation())
		{
			MonsterFight->SetChangeAnimation(CharacterStatus::Idle);
		}

		if (true == PlayerFight->IsAnimationPlaying() && "DEATH" != PlayerFight->GetCurrentAnimation())
		{
			PlayerFight->SetChangeAnimation(CharacterStatus::Idle);

		}
	}
}

