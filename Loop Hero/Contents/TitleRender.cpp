#include "TitleRender.h"
#include <EngineBase/EngineMath.h>


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

	AlphaUpdate(IntroLogoRender, _DeltaTime);
	AlphaUpdate(IntroLogoRender2, _DeltaTime);

	BackTime -= _DeltaTime;
	if (0 >= BackTime)
	{
		if (1 >= BackAlpha)
		{
			BackAlpha += 0.5f * _DeltaTime;
			BackGroundImageRender->SetAlpha(BackAlpha);
		}
	}

	LogoTime -= _DeltaTime;
	if (0 >= LogoTime)
	{
		if (1 >= LogoAlpha)
		{
			LogoAlpha += 0.5f * _DeltaTime;
			TitleLogoRender->SetAlpha(LogoAlpha);
		}
	}

	TitleMoveTime -= _DeltaTime;
	if (0 >= TitleMoveTime)
	{
		MenuMove(_DeltaTime);

	}

}

void ATitleRender::IntroLogo()
{
	IntroBackGroundRender = CreateImageRenderer();
	IntroBackGroundRender->SetOrder(0);
	IntroBackGroundRender->SetImage("Intro_BackGround.png");
	UWindowImage* IntroBackGroundImage = IntroBackGroundRender->GetImage();
	FVector IntroBackGroundScale = IntroBackGroundImage->GetScale();
	IntroBackGroundRender->SetTransform({ IntroBackGroundScale.Half2D(),IntroBackGroundScale });

	IntroLogoRender = CreateImageRenderer();
	IntroLogoRender->SetOrder(1);
	IntroLogoRender->SetImage("Intro_logo_1.png");
	UWindowImage* IntroLogoImage = IntroLogoRender->GetImage();
	FVector IntroLogoScale = IntroLogoImage->GetScale();
	IntroLogoRender->SetTransform({ IntroBackGroundScale.Half2D(),IntroLogoScale });
	IntroLogoRender->Destroy(4.0);

	IntroLogoRender2 = CreateImageRenderer();
	IntroLogoRender2->SetOrder(1);
	IntroLogoRender2->SetActive(true, 4.0f);
	IntroLogoRender2->SetImage("Intro_logo_2.png");
	UWindowImage* IntroLogoImage2 = IntroLogoRender->GetImage();
	FVector IntroLogoScale2 = IntroLogoImage->GetScale();
	IntroLogoRender2->SetTransform({ IntroBackGroundScale.Half2D(),IntroLogoScale });
	IntroLogoRender2->Destroy(8.0);
}

void ATitleRender::BackGroundImage()
{
	BackGroundImageRender = CreateImageRenderer();
	BackGroundImageRender->SetOrder(0);
	BackGroundImageRender->SetActive(true, 8.0f);
	BackGroundImageRender->SetAlpha(BackAlpha);
	BackGroundImageRender->SetImage("TitleBackGround.png");
	UWindowImage* BackGroundImage = BackGroundImageRender->GetImage();
	FVector BackGroundScale = BackGroundImage->GetScale();
	BackGroundImageRender->SetTransform({ BackGroundScale.Half2D(),BackGroundScale });
}

void ATitleRender::TitleMenu()
{
	MenuRender = CreateImageRenderer();
	MenuRender->SetOrder(1);
	MenuRender->SetActive(true, 10.0f);
	MenuRender->SetImage("ScreenMenu.png");

	TitleLogoRender = CreateImageRenderer();
	TitleLogoRender->SetOrder(3);
	TitleLogoRender->SetActive(true, 10.0f);
	TitleLogoRender->SetAlpha(LogoAlpha);
	TitleLogoRender->SetImage("TitleLogo.png");
	TitleLogoRender->SetTransform({ {640, 325}, {380, 400} });

	PlayButtonRender = CreateImageRenderer();
	PlayButtonRender->SetOrder(2);
	PlayButtonRender->SetActive(true, 10.0f);
	PlayButtonRender->SetImage("s_button_start_0.png");
}

void ATitleRender::MenuMove(float _DeltaTime)
{
	MenuDT += _DeltaTime / 1.0f;
	FVector TitleLogoStartPos = { 640, 325 };
	FVector TitleLogoEndPos = { 640, 140 };
	FVector TitleMovePos = float4::LerpClamp(TitleLogoStartPos, TitleLogoEndPos, MenuDT);
	TitleLogoRender->SetTransform({ {TitleMovePos.X, TitleMovePos.Y}, {380, 400} });

	FVector MenuStartPos = { 640, -620 };
	FVector MenuEndPos = { 640, 310 };
	FVector MenuRenderPos = float4::LerpClamp(MenuStartPos, MenuEndPos, MenuDT);
	MenuRender->SetTransform({ {MenuRenderPos.X, MenuRenderPos.Y}, {225, 880} });

	FVector PlayButtonStartPos = { 640, -620 };
	FVector PlayButtonEndPos = { 640, 360 };
	FVector PlayButtonPos = float4::LerpClamp(PlayButtonStartPos, PlayButtonEndPos, MenuDT);
	PlayButtonRender->SetTransform({ {PlayButtonPos.X, PlayButtonPos.Y}, {180, 40} });



}

void ATitleRender::AlphaUpdate(UImageRenderer* _RendererAlpha, float _DeltaTime)
{
	if (IsAlphaIncreasing)
	{
		IntroAlpha += 0.25f * _DeltaTime;

		if (1.0f <= IntroAlpha)
		{
			IntroAlpha = 1.0f;
			IsAlphaIncreasing = false;
		}
	}
	else
	{
		IntroAlpha -= 0.25f * _DeltaTime;

		if (0 >= IntroAlpha)
		{
			IntroAlpha = 0.0f;
			IsAlphaIncreasing = true;
		}
	}

	_RendererAlpha->SetAlpha(IntroAlpha);
}
