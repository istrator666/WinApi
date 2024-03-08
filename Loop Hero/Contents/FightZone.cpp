#include "FightZone.h"
#include "TestStageLevel.h"

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
		if (MonsterFight->GetCurrentAnimationName() == "DEATH" && true == MonsterFight->IsAnimationEnd())
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
	if ("DEATH" == PlayerFight->GetCurrentAnimationName())
	{
		return;
	}

	// 플레이어 사망
	{
		if (PlayerFight->IsDeath() && PlayerFight->GetCurrentAnimationName() != "DEATH")
		{
			PlayerFight->SetChangeAnimation(CharacterStatus::Death);
		}
	}

	// 몬스터 사망
	{
		for (AMonsterFight* MonsterFight : MonsterFights)
		{
			if (true == MonsterFight->IsDeath() && MonsterFight->GetCurrentAnimationName() != "DEATH")
			{
				UTestStageLevel* Level = dynamic_cast<UTestStageLevel*>(GetWorld());
				Level->MonsterDrop(MonsterFight->GetActorLocation());
				MonsterFight->SetChangeAnimation(CharacterStatus::Death);
			}
		}
	}

	// 플레이어 공격
	{
		AMonsterFight* TargetMonster = nullptr;

		for (AMonsterFight* MonsterFight : MonsterFights)
		{
			if (false == MonsterFight->IsDeath())
			{
				TargetMonster = MonsterFight;
				break;
			}
		}

		if (nullptr != TargetMonster)
		{
			if (!PlayerFight->IsDeath())
			{
				int PlayerAttackGauge = static_cast<int>((PlayerFight->GetAttackGauge() / 100) * 52);
				PlayerFight->SetPlyerAttackGaugeBar(PlayerAttackGauge);
			}
			bool AttCheck = PlayerFight->AttackSpeed(*PlayerFight, _DeltaTime);

			if (PlayerFight->GetCurrentAnimationName() != "ATTACK")
			{
				if (true == AttCheck)
				{
					PlayerFight->SetChangeAnimation(CharacterStatus::Attack);
					PlayerFight->AttackDamege(*PlayerFight, *TargetMonster);

					int CurrentHPBar = TargetMonster->GetHP();
					int HPbar = static_cast<int>((static_cast<float>(CurrentHPBar) / TargetMonster->GetMaxHP()) * 52);
					TargetMonster->SetMonsterHPbar(HPbar);

					if ("ATTACK" != TargetMonster->GetCurrentAnimationName())
					{
						TargetMonster->SetChangeAnimation(CharacterStatus::Hurt);
					}
				}
			}
			else if (PlayerFight->GetCurrentAnimationName() == "ATTACK" && true == PlayerFight->IsAnimationEnd())
			{
				PlayerFight->SetChangeAnimation(CharacterStatus::Idle);
			}

		}
	}

	// 몬스터 공격
	{
		for (AMonsterFight* MonsterFight : MonsterFights)
		{
			if (true == MonsterFight->IsDeath())
			{
				if (true == PlayerFight->IsAnimationEnd() && "DEATH" != PlayerFight->GetCurrentAnimationName())
				{
					PlayerFight->SetChangeAnimation(CharacterStatus::Idle);
				}
				continue;
			}

			if (!MonsterFight->IsDeath())
			{
				int MonsterAttackGauge = static_cast<int>((MonsterFight->GetAttackGauge() / 100) * 52);
				MonsterFight->SetPlyerAttackGaugeBar(MonsterAttackGauge);
			}
			bool AttCheck = MonsterFight->AttackSpeed(*MonsterFight, _DeltaTime);

			if (MonsterFight->GetCurrentAnimationName() != "ATTACK")
			{
				if (true == AttCheck)
				{
					MonsterFight->SetChangeAnimation(CharacterStatus::Attack);
					MonsterFight->AttackDamege(*MonsterFight, *PlayerFight);

					int CurrentHPBar = PlayerFight->GetHP();
					int HPbar = static_cast<int>((static_cast<float>(CurrentHPBar) / PlayerFight->GetMaxHP()) * 52);
					PlayerFight->SetPlayerHPbar(HPbar);

					if ("ATTACK" != PlayerFight->GetCurrentAnimationName())
					{
						PlayerFight->SetChangeAnimation(CharacterStatus::Hurt);
					}
				}
			}
			else if (MonsterFight->GetCurrentAnimationName() == "ATTACK" && true == MonsterFight->IsAnimationEnd())
			{
				MonsterFight->SetChangeAnimation(CharacterStatus::Idle);
			}

		}
	}
}

