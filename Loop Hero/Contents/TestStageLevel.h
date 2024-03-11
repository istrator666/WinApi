#pragma once
#include <EngineCore/Level.h>
#include "StageMap.h"
#include "Player.h"
#include "Monster.h"
#include "EQInventory.h"
#include "CardInventory.h"
#include "StageUI.h"
#include "FightZone.h"
#include "Enum.h"

#include <EngineBase/EngineRandom.h>
#include "Struct.h"

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
	MonsterType GetMonsterType();

	//Pause
	void GamePause();

	// Drop
	void MonsterDrop(FVector _MonsterPosition);

	// Ÿ�ϸ� ����
	void InitTileMap();
	std::map<__int64, int> TileMap;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	UEngineRandom RandomEngine;

	// �ʵ� �÷��̾�, ����
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

	// �÷��̾�, ���� �̵�
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);
	std::vector<FVector> MonsterMovePoints(FVector _Location);
	void StageMoveMonster(AMonster* _Monster, FVector _Location);

	// Ÿ��, ���� ����
	AStageMap* Stage = nullptr;
	bool TileSetup = false;
	float SpawnTimeCheck = 0.0f;
	std::vector<SpawnTileData> mSpawn;
	std::vector<SpawnTileData> SpawnTileLocation();
	std::vector<SpawnTileData> SpawnTile;
	FVector RandomSpawnLocation(FVector _Location);
	void SpawnTileType(SpawnTileData& _TileData);
	void MonsterSpawn(SpawnTileData& _TileData, MonsterType _MonsterType);

	// �ʱ� �÷��̾� ����
	EStageState CurState = EStageState::Move;

	bool IsGamePause = false;
};