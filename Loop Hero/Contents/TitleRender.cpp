#include "TitleRender.h"


ATitleRender::ATitleRender()
{
}

ATitleRender::~ATitleRender()
{
}

void ATitleRender::BeginPlay()
{
	AActor::BeginPlay();

	SetActorLocation({ 640, 360 });
	IntroLogo();
	BackGroundImage();
	TitleMenu();

}

void ATitleRender::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	LogoChageTime -= _DeltaTime;
	if (LogoChageTime <= 0)
	{
		IntroLogoRenderer->SetImage("Intro_logo_2.png");

	}

	TitleMoveTime -= _DeltaTime;
	if (TitleMoveTime <= 0)
	{
		TitleLogoRenderer->SetTransform({ {0, -225}, {350, 350} });
	}
}

void ATitleRender::IntroLogo()
{
	UImageRenderer* IntroBackGroundRenderer = CreateImageRenderer();
	IntroBackGroundRenderer->SetImage("Intro_BackGround.png");
	IntroBackGroundRenderer->SetScale({ 1280,720 });

	IntroLogoRenderer = CreateImageRenderer();
	IntroLogoRenderer->SetImage("Intro_logo_1.png");
	IntroLogoRenderer->SetScale({ 500,250 });
	IntroLogoRenderer->Destroy(4.0);

}

void ATitleRender::BackGroundImage()
{
	UImageRenderer* BackGroundImageRenderer = CreateImageRenderer();
	BackGroundImageRenderer->SetActive(true, 4.0f);
	BackGroundImageRenderer->SetImage("TitleBackGround.png");
	BackGroundImageRenderer->SetScale({ 1280,720 });
}

void ATitleRender::TitleMenu()
{
	UImageRenderer* MenuRenderer = CreateImageRenderer();
	MenuRenderer->SetActive(true, 6.0f);
	MenuRenderer->SetImage("ScreenMenu.png");
	MenuRenderer->SetTransform({ {0,-50}, {220, 880} });

	TitleLogoRenderer = CreateImageRenderer();
	TitleLogoRenderer->SetActive(true, 4.0f);
	TitleLogoRenderer->SetImage("TitleLogo.png");
	TitleLogoRenderer->SetTransform({ {0,-50}, {350, 350} });

	UImageRenderer* PlayButton = CreateImageRenderer();
	PlayButton->SetActive(true, 6.0f);
	PlayButton->SetImage("Button_0.png");
	PlayButton->SetTransform({ {0,0}, {180, 40} });
}
