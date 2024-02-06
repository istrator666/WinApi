#include "Titlelogo.h"

ATitlelogo::ATitlelogo()
{
}

ATitlelogo::~ATitlelogo()
{
}

void ATitlelogo::BeginPlay()
{
	AActor::BeginPlay();

	SetActorLocation({ 640, 360 });
	IntroLogo();
	BackGroundImage();
	TitleMenu();

}

void ATitlelogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	ChangeTime -= _DeltaTime;
	if (ChangeTime < 0.0f)
	{
		IntroLogoRenderer->SetImage("Intro_logo_2.png");
		
	}

	NextBGTime -= _DeltaTime;
	if (NextBGTime < 0.0f)
	{
		BackGroundImageRenderer->SetActive(true);
	}

	NextLogoTime -= _DeltaTime;
	if (NextLogoTime < 0.0f)
	{
		TitleLogoRenderer->SetActive(true);
	}

	NextMenuTime -= _DeltaTime;
	if (NextMenuTime < 0.0f)
	{
		MenuRenderer->SetActive(true);
		TitleLogoRenderer->SetTransform({ {0,-235}, {350, 350} });
	}

}

void ATitlelogo::IntroLogo()
{
	UImageRenderer* IntroBackGroundRenderer = CreateImageRenderer();
	IntroBackGroundRenderer->SetImage("Intro_BackGround.png");
	IntroBackGroundRenderer->SetScale({ 1280,720 });

	IntroLogoRenderer = CreateImageRenderer();

	IntroLogoRenderer->SetImage("Intro_logo_1.png");
	IntroLogoRenderer->SetScale({ 500,250 });

	IntroLogoRenderer->Destroy(4.0);
}

void ATitlelogo::BackGroundImage()
{
	BackGroundImageRenderer = CreateImageRenderer();

	BackGroundImageRenderer->SetImage("TitleBackGround.png");
	BackGroundImageRenderer->SetScale({ 1280,720 });
	BackGroundImageRenderer->SetActive(false);
}

void ATitlelogo::TitleMenu()
{
	MenuRenderer = CreateImageRenderer();
	MenuRenderer->SetActive(false);
	MenuRenderer->SetImage("ScreenMenu.png");
	MenuRenderer->SetTransform({ {0,-50}, {220, 660} });

	TitleLogoRenderer = CreateImageRenderer();
	TitleLogoRenderer->SetActive(false);
	TitleLogoRenderer->SetImage("TitleLogo.png");
	TitleLogoRenderer->SetTransform({ {0,-50}, {350, 350} });

}
