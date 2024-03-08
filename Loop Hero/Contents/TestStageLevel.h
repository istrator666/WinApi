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
	int MonsterCountTile;
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

	// 공통함수
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

	UEngineRandom RandomEngine;

	// 필드 플레이어, 몬스터
	APlayer* Player = nullptr;
	std::vector<AMonster*> Monsters;
	std::vector<AMonster*> FightCheckMonsters;
	AMonster* Monster = nullptr;

	// UI
	StageUI::AStageProgressGauge* StageprogressGauge = nullptr;
	StageUI::ASpeedPanel* SppedPanel = nullptr;
	StageUI::APlashka* APlashka = nullptr;
	StageUI::ATravelitemPanel* TravelitemPanel = nullptr;

	ACardInventory* CardInventory = nullptr;

	EQInventory::AEQInventoryUI* EQInventory = nullptr;

	// Fight
	AFightZone* FightZone = nullptr;
	APlayerFight* PlayerFight = nullptr;
	std::vector<AMonsterFight*> MonsterFights;
	bool IsFight = false;

	// 플레이어, 몬스터 이동
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);
	std::vector<FVector> MonsterMovePoints(FVector _Location);
	void StageMoveMonster(AMonster* _Monster, FVector _Location);


	// 타일, 몬스터 생성
	bool TileSetup = false;
	float SpawnTimeCheck = 0.0f;
	int MonsterSpawnCount = 0;
	std::vector<SpawnTileData> mSpawn;
	std::vector<SpawnTileData> SpawnTileLocation();
	FVector RandomSpawnLocation(FVector _Location);
	void SpawnTileType(SpawnTileData& _TileData);
	void MonsterSpawn(SpawnTileData& _TileData);


	// 초기 플레이어 상태
	EStageState CurState = EStageState::Move;

	bool IsGamePause = false;
};