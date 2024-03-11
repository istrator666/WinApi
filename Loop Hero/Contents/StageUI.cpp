#include "StageUI.h"
#include "MouseFunction.h"

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
	Mousehover();
}

void StageUI::AStageProgressGauge::StageProgressGaugeUpdate(float _DeltaTime)
{
	ElapsedTime += _DeltaTime;

	DailyGaugeUpdate = static_cast<int>(ElapsedTime / 5 * 195);

	if (195 <= DailyGaugeUpdate)
	{
		ElapsedTime = 0.0f;
		DailyGaugeUpdate = 0;
	}
	StageProgressGaugeBarDaily->SetTransform({ {-86, -15}, {DailyGaugeUpdate, 20} });

	if (true) // 타일 수에 따라 게이지 상승
	{
		StageProgressGaugeBarBoss->SetTransform({ {-86, 15}, {100, 20} });
	}
}

void StageUI::AStageProgressGauge::Mousehover()
{
	FVector PosCheck = UMouseFunction::GetMousePos();
	int  DescriptionPositionX = static_cast<int>(PosCheck.X) - 100;
	int  DescriptionPositionY = static_cast<int>(PosCheck.Y) + 25;

	if ((20 <= PosCheck.X && 225 >= PosCheck.X) && (0 <= PosCheck.Y && 20 >= PosCheck.Y))
	{

		DailyDescription->SetActive(true);
		DailyDescription->SetTransform({ {DescriptionPositionX, DescriptionPositionY }, {200,100} });
	}
	else
	{
		DailyDescription->SetActive(false, 0.1f);
	}

	if ((20 <= PosCheck.X && 225 >= PosCheck.X) && (40 <= PosCheck.Y && 60 >= PosCheck.Y))
	{
		BossDescription->SetActive(true);
		BossDescription->SetTransform({ {DescriptionPositionX, DescriptionPositionY}, {200,100} });
	}
	else
	{
		BossDescription->SetActive(false, 0.1f);
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

	DailyDescription = CreateImageRenderer();
	DailyDescription->SetImage("Description.png");
	DailyDescription->SetOrder(7);
	DailyDescription->SetActive(false, 0.1f);

	BossDescription = CreateImageRenderer();
	BossDescription->SetImage("Description.png");
	BossDescription->SetOrder(7);
	BossDescription->SetActive(false, 0.1f);
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
	TravelitemPanelRender->SetActive(false);
	TravelitemPanelRender->SetOrder(5);
	TravelitemPanelRender->SetTransform({ {0, 0}, {365,50} });
}
