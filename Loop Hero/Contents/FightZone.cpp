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

void AFightZone::FightZoneInit(APlayerFight* _PlayerFight, std::vector<AMonsterFight*>& _MonsterFights)
{
	PlayerFight = _PlayerFight;
	MonsterFights = _MonsterFights;
}

bool AFightZone::AllMonsterDeath()
{
	int DeathMonsterCount = 0;

	for (auto& MonsterFight : MonsterFights)
	{
		if (true == MonsterFight->IsDeath())
		{
			++DeathMonsterCount;
		}
	}

	if (DeathMonsterCount == MonsterFights.size())
	{
		return true;
	}

	return false;
}

void AFightZone::Battle(float _DeltaTime)
{
	bool allMonstersDead = true;
	

	if ("DEATH" == PlayerFight->GetCurrentAnimation())
	{
		return;
	}

	for (auto& MonsterFight : MonsterFights)
	{
		if (MonsterFight->IsDeath())
		{
			continue;
		}

		if (nullptr != PlayerFight && nullptr != MonsterFight)
		{
			int PlayerAttackGauge = static_cast<int>((PlayerFight->GetAttackGauge() / 100) * 52);
			PlayerFight->SetPlyerAttackGaugeBar(PlayerAttackGauge);
			int MonsterAttackGauge = static_cast<int>((MonsterFight->GetAttackGauge() / 100) * 52);
			MonsterFight->SetPlyerAttackGaugeBar(MonsterAttackGauge);

			if (true == PlayerFight->AttackSpeed(*PlayerFight, _DeltaTime))
			{
				if (!MonsterFight->IsDeath())
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
			}

			if (true == MonsterFight->AttackSpeed(*MonsterFight, _DeltaTime))
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
}

