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
		StageProgressGaugeBarBoss->SetTransform({ {-86, 15}, {0, 20} });
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

	SpeedPanelText01 = CreateImageRenderer();
	SpeedPanelText01->SetText("1.0x");
	SpeedPanelText01->SetTextSortOption(Gdiplus::StringAlignmentNear, Gdiplus::StringAlignmentNear);
	SpeedPanelText01->SetTextSize(17);
	SpeedPanelText01->SetTextColor(Color8Bit::White);
	SpeedPanelText01->SetOrder(6);
	SpeedPanelText01->SetTransform({ { 35, -20 }, {0, 0} });

	SpeedPanelText02 = CreateImageRenderer();
	SpeedPanelText02->SetText("1.0x");
	SpeedPanelText02->SetTextSortOption(Gdiplus::StringAlignmentNear, Gdiplus::StringAlignmentNear);
	SpeedPanelText02->SetTextSize(17);
	SpeedPanelText02->SetTextColor(Color8Bit::White);
	SpeedPanelText02->SetOrder(6);
	SpeedPanelText02->SetTransform({ { 35, 5 }, {0, 0} });
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

	PlashkaText = CreateImageRenderer();
	PlashkaText->SetText("계획");
	PlashkaText->SetTextSortOption(Gdiplus::StringAlignmentNear, Gdiplus::StringAlignmentNear);
	PlashkaText->SetTextSize(25);
	PlashkaText->SetTextColor(Color8Bit::White);
	PlashkaText->SetOrder(6);
	PlashkaText->SetTransform({ { 0, -10}, {0, 0} });

	PlashkaPause = CreateImageRenderer();
	PlashkaPause->SetImage("PlashkaPause.png");
	PlashkaPause->SetOrder(6);
	PlashkaPause->SetTransform({ {-118, 0}, {250,250} });
	PlashkaPause->CreateAnimation("Idle", "PlashkaPause.png", 4, 4, 0.3f, false);
	PlashkaPause->ChangeAnimation("Idle");
	PlashkaPause->SetActive(true);


	PlashkaMove = CreateImageRenderer();
	PlashkaMove->SetImage("PlashkaMove.png");
	PlashkaMove->SetOrder(6);
	PlashkaMove->SetTransform({ {-118, 0}, {250,250} });
	PlashkaMove->CreateAnimation("Idle", "PlashkaMove.png", 0, 15, 0.25f, true);
	PlashkaMove->ChangeAnimation("Idle");
	PlashkaMove->SetActive(false);
}

void StageUI::APlashka::ChangePlashka(int _Number)
{
	switch (_Number)
	{
	case 0:
		PlashkaText->SetText("계획");
		PlashkaMove->SetActive(false);
		PlashkaPause->SetActive(true);
		PlashkaPause->ChangeAnimation("Idle");
		break;
	case 1:
		PlashkaText->SetText("모험");
		PlashkaPause->SetActive(false);
		PlashkaMove->SetActive(true);
		PlashkaMove->ChangeAnimation("Idle");
		break;
	default:
		break;
	}
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
