#pragma once
#include <EngineCore/Actor.h>
#include "Player.h"
#include "Monster.h"

class AFightZone : public AActor
{
public:
	// constrcuter destructer
	AFightZone();
	~AFightZone();

	// delete Function
	AFightZone(const AFightZone& _Other) = delete;
	AFightZone(AFightZone&& _Other) noexcept = delete;
	AFightZone& operator=(const AFightZone& _Other) = delete;
	AFightZone& operator=(AFightZone&& _Other) noexcept = delete;

	void FightZoneImage();
	void FightZoneInit(APlayerFight* _PlyerFight, std::vector<AMonsterFight*>& _MonsterFights);

	bool AllMonsterDeath();

	void Battle(float _DeltaTime);
	bool IsBattle = false;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* FightZoneRender = nullptr;
	APlayerFight* PlayerFight;
	std::vector<AMonsterFight*> MonsterFights;

};

