#pragma once
#include <EngineCore/Actor.h>

class AStageUI : public AActor
{
public:
	// constrcuter destructer
	AStageUI();
	~AStageUI();

	// delete Function
	AStageUI(const AStageUI& _Other) = delete;
	AStageUI(AStageUI&& _Other) noexcept = delete;
	AStageUI& operator=(const AStageUI& _Other) = delete;
	AStageUI& operator=(AStageUI&& _Other) noexcept = delete;

	void StageProgressGauge();
	void SpeedPanel();
	void Plashka();
	void TravelitemPanel();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* StageProgressGaugeRender = nullptr;
	UImageRenderer* SpeedPanelRender = nullptr;
	UImageRenderer* PlashkaRender = nullptr;
	UImageRenderer* TravelitemPanelRender = nullptr;
};

