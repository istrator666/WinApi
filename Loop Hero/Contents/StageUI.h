#pragma once
#include <EngineCore/Actor.h>

class StageUI
{
public:
	// constrcuter destructer
	StageUI();
	~StageUI();

	// delete Function
	StageUI(const StageUI& _Other) = delete;
	StageUI(StageUI&& _Other) noexcept = delete;
	StageUI& operator=(const StageUI& _Other) = delete;
	StageUI& operator=(StageUI&& _Other) noexcept = delete;

	class AStageProgressGauge : public AActor
	{
	public:
		void StageProgressGauge();

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* StageProgressGaugeRender = nullptr;
		UImageRenderer* StageProgressGaugeBar = nullptr;
		void StageProgressGaugeUpdate(float _DeltaTime);
	};

	class ASpeedPanel : public AActor
	{
	public:
		void SpeedPanel();

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;
		
	private:
		UImageRenderer* SpeedPanelRender = nullptr;
	};

	class APlashka : public AActor
	{
	public:
		void Plashka();

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* PlashkaRender = nullptr;
	};

	class ATravelitemPanel : public AActor
	{
	public:
		void TravelitemPanel();

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* TravelitemPanelRender = nullptr;
	};

protected:

private:
	
};