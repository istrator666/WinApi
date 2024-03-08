#pragma once
#include <EngineCore/Level.h>
#include "Player.h"
#include "Monster.h"
#include "EQInventory.h"
#include "CardInventory.h"
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

	// void Fight(APlayer* _Player, float _DeltaTime);
	void SetStageUI();
	void SetEQInventory();

	void ChangeState(EStageState _State);
	void StateUpdate(float _DeltaTime);

	// �����Լ�
	void MonsterSpawnTimeCheck(float _DeltaTime);

	// Move
	void MoveStart() {}
	void Move(float _DeltaTime);
	void MonsterFightCheck();

	// Fight
	void FightStart();
	void Fight(float _DeltaTime);
	void FightEnd();

	//Pause
	void GamePause();

	// Drop
	void MonsterDrop(FVector _MonsterPosition);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	APlayer* Player = nullptr;
	std::vector<AMonster*> Monsters;
	std::vector<AMonster*> FightCheckMonsters;
	AMonster* Monster = nullptr;

	StageUI::AStageProgressGauge* StageprogressGauge = nullptr;
	StageUI::ASpeedPanel* SppedPanel = nullptr;
	StageUI::APlashka* APlashka = nullptr;
	StageUI::ATravelitemPanel* TravelitemPanel = nullptr;

	ACardInventory* CardInventory = nullptr;

	EQInventory::AEQInventoryUI* EQInventory = nullptr;

	AFightZone* FightZone = nullptr;
	APlayerFight* PlayerFight = nullptr;

	std::vector<AMonsterFight*> MonsterFights;

	bool TileSetup = false;
	bool IsFight = false;

	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

	std::vector<FVector> MonsterMovePoints(FVector _Location);
	void StageMoveMonster(AMonster* _Monster, FVector _Location);

	std::vector<SpawnTileData> mSpawn;
	FVector RandomSpawnLocation(FVector _Location);
	std::vector<SpawnTileData> SpawnTileLocation();
	void SpawnTileType(FVector _Location, TileType _TileType, MonsterType _MonsterType);
	void MonsterSpawn(FVector _Location, MonsterType _MonsterType);
	float SpawnTimeCheck = 0.0f;

	UEngineRandom RandomEngine;

	EStageState CurState = EStageState::Move;
	bool IsGamePause = false;
};