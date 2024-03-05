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

void AFightZone::Battle(APlayerFight* _PlayerFight, std::vector<AMonsterFight*> _MonsterFights, float _DeltaTime)
{
	PlayerFight = _PlayerFight;
	MonsterFights = _MonsterFights;

	bool allMonstersDead = true;

	for (auto& MonsterFight : MonsterFights)
	{
		if (nullptr != PlayerFight && nullptr != MonsterFight)
		{
			if (true == PlayerFight->AttackSpeed(*PlayerFight, _DeltaTime)
				&& "DEATH" != MonsterFight->GetCurrentAnimation()
				&& "DEATH" != PlayerFight->GetCurrentAnimation()
				&& "ATTACK" != PlayerFight->GetCurrentAnimation())
			{
				PlayerFight->SetChangeAnimation(CharacterStatus::Attack);
				PlayerFight->AttackDamege(*PlayerFight, *MonsterFight);

				int CurrentHPBar = MonsterFight->GetHP();
				int HPbar = static_cast<int>((static_cast<float>(CurrentHPBar) / MonsterFight->GetMaxHP()) * 52);
				MonsterFight->SetMonsterHPbar(HPbar);

				if ("ATTACK" != MonsterFight->GetCurrentAnimation())
				{
					MonsterFight->SetChangeAnimation(CharacterStatus::Hurt);
				}
			}

			if (true == MonsterFight->AttackSpeed(*MonsterFight, _DeltaTime)
				&& "DEATH" != PlayerFight->GetCurrentAnimation()
				&& "DEATH" != MonsterFight->GetCurrentAnimation()
				&& "ATTACK" != MonsterFight->GetCurrentAnimation())
			{
				MonsterFight->SetChangeAnimation(CharacterStatus::Attack);
				MonsterFight->AttackDamege(*MonsterFight, *PlayerFight);

				int CurrentHPBar = PlayerFight->GetHP();
				int HPbar = static_cast<int>((static_cast<float>(CurrentHPBar) / PlayerFight->GetMaxHP()) * 52);
				PlayerFight->SetPlayerHPbar(HPbar);

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
					continue;
				}
			}
			else
			{
				allMonstersDead = false;
			}

			if (true == PlayerFight->IsAnimationPlaying() && "DEATH" != PlayerFight->GetCurrentAnimation())
			{
				PlayerFight->SetChangeAnimation(CharacterStatus::Idle);
			}

			if (true == MonsterFight->IsAnimationPlaying() && "DEATH" != MonsterFight->GetCurrentAnimation())
			{
				MonsterFight->SetChangeAnimation(CharacterStatus::Idle);
			}
		}
	}

	if (PlayerFight->IsDeath())
	{
		PlayerFight->SetChangeAnimation(CharacterStatus::Death);
	}

	if (allMonstersDead)
	{
		IsBattle = true;
		return;
	}
}

