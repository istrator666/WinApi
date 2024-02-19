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
		IntroLogoRender->SetImage("Intro_logo_2.png");

	}

	TitleMoveTime -= _DeltaTime;
	if (TitleMoveTime <= 0)
	{
		TitleLogoRender->SetTransform({ {640, 140}, {380, 400} });
	}

}

void ATitleRender::IntroLogo()
{
	IntroBackGroundRender = CreateImageRenderer();
	IntroBackGroundRender->SetImage("Intro_BackGround.png");
	UWindowImage* IntroBackGroundImage = IntroBackGroundRender->GetImage();
	FVector IntroBackGroundScale = IntroBackGroundImage->GetScale();
	IntroBackGroundRender->SetTransform({ IntroBackGroundScale.Half2D(),IntroBackGroundScale });

	IntroLogoRender = CreateImageRenderer();
	IntroLogoRender->SetImage("Intro_logo_1.png");
	UWindowImage* IntroLogoImage = IntroLogoRender->GetImage();
	FVector IntroLogoScale = IntroLogoImage->GetScale();
	IntroLogoRender->SetTransform({ IntroBackGroundScale.Half2D(),IntroLogoScale });
	IntroLogoRender->Destroy(6.0);
}

void ATitleRender::BackGroundImage()
{
	BackGroundImageRender = CreateImageRenderer();
	BackGroundImageRender->SetActive(true, 6.0f);
	BackGroundImageRender->SetImage("TitleBackGround.png");
	UWindowImage* BackGroundImage = BackGroundImageRender->GetImage();
	FVector BackGroundScale = BackGroundImage->GetScale();
	BackGroundImageRender->SetTransform({ BackGroundScale.Half2D(),BackGroundScale });
}

void ATitleRender::TitleMenu()
{
	MenuRender = CreateImageRenderer();
	MenuRender->SetActive(true, 9.0f);
	MenuRender->SetImage("ScreenMenu.png");
	UWindowImage* MenuImage = MenuRender->GetImage();
	FVector MenuScale = MenuImage->GetScale();
	MenuRender->SetTransform({ {640, 310}, {225, 880} });

	TitleLogoRender = CreateImageRenderer();
	TitleLogoRender->SetActive(true, 7.0f);
	TitleLogoRender->SetImage("TitleLogo.png");
	UWindowImage* TitleLogoImage = TitleLogoRender->GetImage();
	FVector TitleLogoScale = TitleLogoImage->GetScale();
	TitleLogoRender->SetTransform({ {640, 325}, {380, 400} });

	PlayButton = CreateImageRenderer();
	PlayButton->SetActive(true, 9.0f);
	PlayButton->SetImage("Button_0.png");
	UWindowImage* PlayButtonImage = PlayButton->GetImage();
	FVector PlayButtonScale = PlayButtonImage->GetScale();
	PlayButton->SetTransform({ {640, 360}, {180, 40} });
}

