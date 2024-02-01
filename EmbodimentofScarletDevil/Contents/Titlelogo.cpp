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

	UImageRenderer* TitleRenderer = CreateImageRenderer();

	TitleRenderer->SetImage("TitleMenu.png");
	SetActorLocation({640, 360});
	TitleRenderer->SetTransform({ {0,0}, {100, 100} });
	TitleRenderer->SetImageCuttingTransform({ {0,0}, {640, 481} });
	TitleRenderer->SetScale({ 1280,721 });
}

void ATitlelogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}
