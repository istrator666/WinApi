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
		int GetDailyGaugeUpdate()
		{
			return DailyGaugeUpdate;
		}
	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		int DailyGaugeUpdate = 0;
		float ElapsedTime = 0.0f;
		UImageRenderer* StageProgressGaugeRender = nullptr;
		UImageRenderer* StageProgressGaugeBarDaily = nullptr;
		UImageRenderer* StageProgressGaugeBarBoss = nullptr;

		UImageRenderer* DailyDescription = nullptr;
		UImageRenderer* BossDescription = nullptr;
		void StageProgressGaugeUpdate(float _DeltaTime);
		void Mousehover();
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
		void Mousehover();
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
		void Mousehover();
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
		void Mousehover();
	};

protected:

private:
	
};