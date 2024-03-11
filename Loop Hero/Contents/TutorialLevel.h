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

#include <EngineBase/EngineRandom.h>
#include "Struct.h"


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

	// Move
	void Move(float _DeltaTime);

	//Pause
	void GamePause();

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

	// 플레이어
	APlayer* Player = nullptr;

	// 플레이어 이동
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

	// 대화
	ADiaLog* DiaLog = nullptr;

	// 초기 플레이어 상태
	EStageState CurState = EStageState::Pause;

	bool IsGamePause = false;

};

