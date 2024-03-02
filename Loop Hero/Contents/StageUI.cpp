#include "StageUI.h"

StageUI::StageUI()
{
}

StageUI::~StageUI()
{
}

void StageUI::AStageProgressGauge::BeginPlay()
{
	AActor::BeginPlay();
	StageProgressGauge();
}

void StageUI::AStageProgressGauge::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	StageProgressGaugeUpdate(_DeltaTime);
}

void StageUI::AStageProgressGauge::StageProgressGaugeUpdate(float _DeltaTime)
{
	ElapsedTime += _DeltaTime;

	int GaugeUpdate = static_cast<int>(ElapsedTime / 5 * 195);

	if (195 <= GaugeUpdate)
	{
		ElapsedTime = 0.0f;
		GaugeUpdate = 0;
	}
	StageProgressGaugeBarDaily->SetTransform({ {-86, -15}, {GaugeUpdate, 20} });

	if (true) // 타일 수에 따라 게이지 상승
	{
		StageProgressGaugeBarBoss->SetTransform({ {-86, 15}, {100, 20} });
	}


}

void StageUI::AStageProgressGauge::StageProgressGauge()
{
	StageProgressGaugeRender = CreateImageRenderer();
	StageProgressGaugeRender->SetImage("StageProgressGauge.png");
	StageProgressGaugeRender->SetOrder(5);
	StageProgressGaugeRender->SetTransform({ {0, 0}, {230,50} });

	StageProgressGaugeBarDaily = CreateImageRenderer();
	StageProgressGaugeBarDaily->SetImage("StageProgressGaugebar.png");
	StageProgressGaugeBarDaily->SetSortType(EImageSortType::Left);
	StageProgressGaugeBarDaily->SetOrder(6);

	StageProgressGaugeBarBoss = CreateImageRenderer();
	StageProgressGaugeBarBoss->SetImage("StageProgressGaugebar.png");
	StageProgressGaugeBarBoss->SetSortType(EImageSortType::Left);
	StageProgressGaugeBarBoss->SetOrder(6);
}

void StageUI::ASpeedPanel::BeginPlay()
{
	AActor::BeginPlay();
	SpeedPanel();
}

void StageUI::ASpeedPanel::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void StageUI::ASpeedPanel::SpeedPanel()
{
	SpeedPanelRender = CreateImageRenderer();
	SpeedPanelRender->SetImage("s_speedpanel_1.png");
	SpeedPanelRender->SetOrder(5);
	SpeedPanelRender->SetTransform({ {0, 0}, {150,50} });
}

void StageUI::APlashka::BeginPlay()
{
	AActor::BeginPlay();
	Plashka();
}

void StageUI::APlashka::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void StageUI::APlashka::Plashka()
{
	PlashkaRender = CreateImageRenderer();
	PlashkaRender->SetImage("s_plashka.png");
	PlashkaRender->SetOrder(5);
	PlashkaRender->SetTransform({ {0, 0}, {300,50} });
}

void StageUI::ATravelitemPanel::BeginPlay()
{
	AActor::BeginPlay();
	TravelitemPanel();
}

void StageUI::ATravelitemPanel::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void StageUI::ATravelitemPanel::TravelitemPanel()
{
	TravelitemPanelRender = CreateImageRenderer();
	TravelitemPanelRender->SetImage("s_travelitempanel.png");
	TravelitemPanelRender->SetOrder(5);
	TravelitemPanelRender->SetTransform({ {0, 0}, {365,50} });
}
