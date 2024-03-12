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
		void StageProgressGaugeUpdate(float _DeltaTime);
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
		UImageRenderer* SpeedPanelText01 = nullptr;
		UImageRenderer* SpeedPanelText02 = nullptr;
		void Mousehover();
	};

	class APlashka : public AActor
	{
	public:
		void Plashka();
		void ChangePlashka(int _Number);

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* PlashkaRender = nullptr;
		UImageRenderer* PlashkaText = nullptr;
		UImageRenderer* PlashkaPause = nullptr;
		UImageRenderer* PlashkaMove = nullptr;
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