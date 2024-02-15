#include "TutorialRander.h"

ATutorialRander::ATutorialRander()
{
}

ATutorialRander::~ATutorialRander()
{
}

void ATutorialRander::BeginPlay()
{
	AActor::BeginPlay();
	SetActorLocation({ 640, 360 });
	TutorialStage();
	TutorialBaseCamp();
}

void ATutorialRander::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (false == GameIntroCheck)
	{
		GameIntro();
	}
}

void ATutorialRander::GameIntro()
{
	UImageRenderer* GameStartIntro = CreateImageRenderer();
	std::string ImageString = std::to_string(ImageNumber) + ".png";
	std::string_view IntroImage = ImageString;
	GameStartIntro->SetScale({ 1280,720 });
	GameStartIntro->SetImage(IntroImage);

	if (114 >= ImageNumber)
	{
		++ImageNumber;
		GameStartIntro->Destroy(0.1f);
	}

	if (115 == ImageNumber)
	{
		GameIntroCheck = true;
	}
}

void ATutorialRander::TutorialStage()
{
	UImageRenderer* TutoBackStage = CreateImageRenderer();
	TutoBackStage->SetImage("StageBackGround.png");
	TutoBackStage->SetScale({ 1280,720 });

	UImageRenderer* TutoMainStage = CreateImageRenderer();
	TutoMainStage->SetImage("TutorialStage01.png");
	TutoMainStage->SetScale({ 250,250 });

}

void ATutorialRander::TutorialBaseCamp()
{
	UImageRenderer* TutoBaseCamp = CreateImageRenderer();
	TutoBaseCamp->SetImage("s_lager_0.png");
	TutoBaseCamp->SetScale({ 50,50 });
	TutoBaseCamp->SetPosition({50, -100});
}




