#include "IntroRender.h"
#include <EnginePlatform/EngineInput.h>

AIntroRender::AIntroRender()
{
}

AIntroRender::~AIntroRender()
{
}

void AIntroRender::BeginPlay()
{
	AActor::BeginPlay();
	GameStartIntro = CreateImageRenderer();

	IntroBackButton = CreateImageRenderer();
	IntroSkipButton = CreateImageRenderer();
	IntroProgressIcon = CreateImageRenderer();

	IntroBackButton->SetImage("s_dia_back_button_0.png");
	IntroBackButton->SetTransform({ {115, 650}, {70, 30 } });
	IntroBackButton->SetOrder(9);
	IntroBackButton->SetActive(false);

	IntroSkipButton->SetImage("s_dia_skip_button_0.png");
	IntroSkipButton->SetTransform({ {230, 650}, {70, 30 } });
	IntroSkipButton->SetOrder(9);
	IntroSkipButton->SetActive(false);

	IntroProgressIcon->SetImage("s_dia_back_button_0.png");
	//IntroProgressIcon->SetActive(false);

}

void AIntroRender::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Sleep(100);
	std::string ImageString = std::to_string(ImageNumber) + ".png";
	std::string_view IntroImage = ImageString;
	GameStartIntro->SetImage(IntroImage);
	UWindowImage* GameIntroImagae = GameStartIntro->GetImage();
	FVector ImageScale = GameIntroImagae->GetScale();
	GameStartIntro->SetTransform({ ImageScale.Half2D(), ImageScale });

	PosCheck = UMouseFunction::GetMousePos();

}

void AIntroRender::GameIntro()
{
	//if (115 >= ImageNumber)
	//{
	//	++ImageNumber;
	//	GameStartIntro->Destroy(3.0f);
	//}

	//if (116 == ImageNumber)
	//{
	//	GameIntroEnd = true;
	//}
}
