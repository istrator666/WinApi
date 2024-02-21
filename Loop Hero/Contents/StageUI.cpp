#include "StageUI.h"

AStageUI::AStageUI()
{
}

AStageUI::~AStageUI()
{
}

void AStageUI::BeginPlay()
{
	AActor::BeginPlay();
	StageProgressGauge();
	SpeedPanel();
	Plashka();
	TravelitemPanel();
}

void AStageUI::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void AStageUI::StageProgressGauge()
{
	StageProgressGaugeRender = CreateImageRenderer();
	StageProgressGaugeRender->SetImage("StageProgressGauge.png");
	StageProgressGaugeRender->SetOrder(5);
	StageProgressGaugeRender->SetTransform({ {115, 25}, {230,50} });
}

void AStageUI::SpeedPanel()
{
	StageProgressGaugeRender = CreateImageRenderer();
	StageProgressGaugeRender->SetImage("s_speedpanel_1.png");
	StageProgressGaugeRender->SetOrder(5);
	StageProgressGaugeRender->SetTransform({ {308, 25}, {150,50} });
}

void AStageUI::Plashka()
{
	PlashkaRender = CreateImageRenderer();
	PlashkaRender->SetImage("s_plashka.png");
	PlashkaRender->SetOrder(5);
	PlashkaRender->SetTransform({ {533, 25}, {300,50} });
}

void AStageUI::TravelitemPanel()
{
	TravelitemPanelRender = CreateImageRenderer();
	TravelitemPanelRender->SetImage("s_travelitempanel.png");
	TravelitemPanelRender->SetOrder(5);
	TravelitemPanelRender->SetTransform({ {866, 25}, {365,50} });
}
