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
}

void StageUI::AStageProgressGauge::StageProgressGauge()
{
	StageProgressGaugeRender = CreateImageRenderer();
	StageProgressGaugeRender->SetImage("StageProgressGauge.png");
	StageProgressGaugeRender->SetOrder(5);
	StageProgressGaugeRender->SetTransform({ {0, 0}, {230,50} });
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
