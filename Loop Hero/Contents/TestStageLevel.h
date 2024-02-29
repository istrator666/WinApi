#pragma once
#include <EngineCore/Level.h>
#include "Player.h"
#include "Monster.h"
#include "EQInventory.h"
#include "StageUI.h"
#include "FightZone.h"
#include "Enum.h"


class UTestStageLevel : public ULevel
{
public:
	// constrcuter destructer
	UTestStageLevel();
	~UTestStageLevel();

	// delete Function
	UTestStageLevel(const UTestStageLevel& _Other) = delete;
	UTestStageLevel(UTestStageLevel&& _Other) noexcept = delete;
	UTestStageLevel& operator=(const UTestStageLevel& _Other) = delete;
	UTestStageLevel& operator=(UTestStageLevel&& _Other) noexcept = delete;

	void Fight(APlayer* _Player, AMonster* _Monster, float _DeltaTime);
	void SetStageUI();
	void SetEQInventory();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	APlayer* Player = nullptr;
	AMonster* Monster = nullptr;

	StageUI::AStageProgressGauge* StageprogressGauge = nullptr;
	StageUI::ASpeedPanel* SppedPanel = nullptr;
	StageUI::APlashka* APlashka = nullptr;
	StageUI::ATravelitemPanel* TravelitemPanel = nullptr;
	
	EQInventory::AEQInventoryUI* EQInventory = nullptr;
	
	AFightZone* FightZone = nullptr;
	APlayerFight* PlayerFight = nullptr;
	AMonsterFight* MonsterFight = nullptr;

	bool TileSetup = false;
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

	std::vector<FVector> MonterMovePoints();
	void StageMoveMonster(AMonster* _Monster);

};

