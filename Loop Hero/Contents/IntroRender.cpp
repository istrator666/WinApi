#include "IntroRender.h"

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
}

void AIntroRender::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	if (false == GameIntroCheck)
	{
		GameIntro();
	}
}

void AIntroRender::GameIntro()
{
	Sleep(100);
	std::string ImageString = std::to_string(ImageNumber) + ".png";
	std::string_view IntroImage = ImageString;
	GameStartIntro->SetImage(IntroImage);
	UWindowImage* GameIntroImagae = GameStartIntro->GetImage();
	FVector ImageScale = GameIntroImagae->GetScale();
	GameStartIntro->SetTransform({ ImageScale.Half2D(), ImageScale });

	if (115 >= ImageNumber)
	{
		++ImageNumber;
		GameStartIntro->Destroy(3.0f);
	}

	if (116 == ImageNumber)
	{
		GameIntroCheck = true;
	}
}