#pragma once
#include <EngineCore/Level.h>
#include "Player.h"
#include "Monster.h"
#include "EQInventory.h"
#include "StageUI.h"
#include "FightZone.h"
#include "Enum.h"
#include <EngineBase/EngineRandom.h>

struct SpawnTileData {
	FVector TileLocation;
	TileType Tile;
	MonsterType Monster;
};


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

	void Fight(APlayer* _Player, float _DeltaTime);
	void SetStageUI();
	void SetEQInventory();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	APlayer* Player = nullptr;
	std::vector<AMonster*> Monsters;
	AMonster* Monster = nullptr;

	StageUI::AStageProgressGauge* StageprogressGauge = nullptr;
	StageUI::ASpeedPanel* SppedPanel = nullptr;
	StageUI::APlashka* APlashka = nullptr;
	StageUI::ATravelitemPanel* TravelitemPanel = nullptr;
	
	EQInventory::AEQInventoryUI* EQInventory = nullptr;
	
	AFightZone* FightZone = nullptr;
	APlayerFight* PlayerFight = nullptr;

	std::vector<AMonsterFight*> MonsterFights;
	AMonsterFight* MonsterFight = nullptr;

	bool TileSetup = false;

	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

	std::vector<FVector> MonsterMovePoints(FVector _Location);
	void StageMoveMonster(AMonster* _Monster, FVector _Location);

	std::vector<SpawnTileData> mSpawn;
	std::vector<SpawnTileData> SpawnTileLocation();

	FVector RandomSpawnLocation(FVector _Location);
	void SpawnTileType(FVector _Location, TileType _TileType, MonsterType _MonsterType);
	void MonsterSpawn(FVector _Location, MonsterType _MonsterType);

	float SpawnTimeCheck = 0.0f;

	UEngineRandom RandomEngine;

};

