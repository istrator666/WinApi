#pragma once
#include <EngineCore/Level.h>
#include "Player.h"
#include "Monster.h"
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool TileSetup = false;
	std::vector<FVector> StagePoints(const std::string& _StageName);
	void StageMovePlayer(APlayer* _Player);

};

