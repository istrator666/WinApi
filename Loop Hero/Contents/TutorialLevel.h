#pragma once
#include <EngineCore/Level.h>
#include "TutorialRender.h"
#include "Player.h"
#include "Monster.h"
#include "EQInventory.h"
#include "CardInventory.h"
#include "StageUI.h"
#include "FightZone.h"
#include "Enum.h"
#include "DiaLog.h"
#include "Mouse.h"

#include <EngineBase/EngineRandom.h>
#include "Struct.h"
#include <EnginePlatform/EngineSound.h>

class UTutorialLevel : public ULevel
{
public:
	// constrcuter destructer
	UTutorialLevel();
	~UTutorialLevel();

	// delete Function
	UTutorialLevel(const UTutorialLevel& _Other) = delete;
	UTutorialLevel(UTutorialLevel&& _Other) noexcept = delete;
	UTutorialLevel& operator=(const UTutorialLevel& _Other) = delete;
	UTutorialLevel& operator=(UTutorialLevel&& _Other) noexcept = delete;

	void ChangeState(EStageState _State);
	void StateUpdate(float _DeltaTime);

	//���� �Լ�
	void MonsterSpawnTimeCheck(float _DeltaTime);

	// Move
	void Move(float _DeltaTime);
	void MonsterFightCheck();

	// Fight �Լ�
	void FightStart();
	void Fight(float _DeltaTime);
	void FightEnd();
	void SetMonsterType(MonsterType _FightMonsterType);
	MonsterType GetMonsterType();

	//Pause
	void GamePause();

	// Drop
	void MonsterDrop(FVector _MonsterPosition);

	void Talk1(float _DeltaTime);
	void Talk2(float _DeltaTime);
	void Talk3(float _DeltaTime);
	void Talk4(float _DeltaTime);
	void Talk5(float _DeltaTime);
	void Talk6(float _DeltaTime);
	void TutorialEnd();

	void Talk2Start();
	void Talk3Start();
	void Talk4Start();

	//������ ����, ī�� ��ġ
	void TutorialEQGuide();
	void TutorialCardGuide();
	void TutorialEQCardGuide();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	ATutorialRender* TutorialRender = nullptr;
	UEngineRandom RandomEngine;

	// UI
	StageUI::AStageProgressGauge* StageprogressGauge = nullptr;
	StageUI::ASpeedPanel* SppedPanel = nullptr;
	StageUI::APlashka* APlashka = nullptr;
	StageUI::ATravelitemPanel* TravelitemPanel = nullptr;

	ACardInventory* CardInventory = nullptr;

	EQInventory::AEQInventoryUI* EQInventory = nullptr;

	void SetStageUI();
	void SetEQInventory();

	//���콺 ������Ʈ
	AMouse* Mouse = nullptr;

	// �÷��̾�
	APlayer* Player = nullptr;

	// �÷��̾� �̵�
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

	// ��ȭ
	ADiaLog* DiaLog = nullptr;

	// �ʱ� �÷��̾� ����
	EStageState CurState = EStageState::Talk1;

	// Fight
	AFightZone* FightZone = nullptr;
	APlayerFight* PlayerFight = nullptr;
	std::vector<AMonsterFight*> MonsterFights;
	bool IsFight = false;
	bool IsDialog = true;

	// ����
	std::vector<AMonster*> Monsters;
	std::vector<AMonster*> FightCheckMonsters;
	AMonster* Monster = nullptr;

	//���� �̵�
	std::vector<FVector> MonsterMovePoints(FVector _Location);
	void StageMoveMonster(AMonster* _Monster, FVector _Location);

	//���� ����
	MonsterType FightMonsterType;
	float SpawnTimeCheck = 0.0f;
	std::vector<SpawnTileData> mSpawn;
	std::vector<SpawnTileData> SpawnTileLocation();
	std::vector<SpawnTileData> SpawnTile;
	FVector RandomSpawnLocation(FVector _Location);
	void SpawnTileType(SpawnTileData& _TileData);
	void MonsterSpawn(SpawnTileData& _TileData, MonsterType _MonsterType);

	std::vector<SpawnTileData> TutorialSpawnTileLocation();

	bool IsGamePause = false;
	int TalkCount = 0;
	float TimeCheck = 1.0f;
	FVector PlayerLocation;
	bool FightStartCheckTest = true;
	bool IsTalk5 = false;
	bool IsTalk6 = false;
	bool IsGameEnd = false;

	//���� 
	UEngineSoundPlayer BackgroundBGM;
	UEngineSoundPlayer PlayerTalk;
	UEngineSoundPlayer NewDay;
	UEngineSoundPlayer RetreatSound;


	int TutorialDrop = 1;
};

