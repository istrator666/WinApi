#pragma once
#include <EngineCore/Level.h>
#include "Player.h"
#include "Monster.h"
#include "EQInventory.h"
#include "StageUI.h"
#include "FightZone.h"
#include "Enum.h"


class UStageLevel : public ULevel
{
public:
	// constrcuter destructer
	UStageLevel();
	~UStageLevel();

	// delete Function
	UStageLevel(const UStageLevel& _Other) = delete;
	UStageLevel(UStageLevel&& _Other) noexcept = delete;
	UStageLevel& operator=(const UStageLevel& _Other) = delete;
	UStageLevel& operator=(UStageLevel&& _Other) noexcept = delete;

	void Fight(APlayer* _Player, AMonster* _Monster);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	APlayer* Player = nullptr;
	AMonster* Monster = nullptr;
	AEQInventory* EQInventory = nullptr;
	AStageUI* StageUI = nullptr;
	AFightZone* FightZone = nullptr;

	bool TileSetup = false;
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

};

