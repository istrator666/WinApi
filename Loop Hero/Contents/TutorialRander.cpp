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
	GameIntro();
	TutorialStage();
	TutorialBaseCamp();
	PlayerRender();
}

void ATutorialRander::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void ATutorialRander::GameIntro()
{
	UImageRenderer* GameStartIntro = CreateImageRenderer();
	GameStartIntro->SetImage("001.png");
	GameStartIntro->SetScale({ 1280,720 });
	GameStartIntro->CreateAnimation("GameIntro", "001.png", 0, 10, 0.3f, false);
	GameStartIntro->ChangeAnimation("GameIntro");
}

void ATutorialRander::TutorialStage()
{
	UImageRenderer* TutoBackStage = CreateImageRenderer();
	TutoBackStage->SetActive(true, 10.0f);
	TutoBackStage->SetImage("StageBackGround.png");
	TutoBackStage->SetScale({ 1280,720 });

	UImageRenderer* TutoMainStage = CreateImageRenderer();
	TutoMainStage->SetActive(true, 10.0f);
	TutoMainStage->SetImage("TutorialStage01.png");
	TutoMainStage->SetScale({ 250,250 });

}

void ATutorialRander::TutorialBaseCamp()
{
	UImageRenderer* TutoBaseCamp = CreateImageRenderer();
	TutoBaseCamp->SetActive(true, 10.0f);
	TutoBaseCamp->SetImage("s_lager_0.png");
	TutoBaseCamp->SetScale({ 50,50 });
	TutoBaseCamp->SetPosition({50, -100});
}

void ATutorialRander::PlayerRender()
{
	UImageRenderer* Player = CreateImageRenderer();
	Player->SetActive(true, 10.0f);
	Player->SetImage("WarriorPlayer.png");
	Player->SetTransform({ {50,-100}, {100, 100} });
	Player->CreateAnimation("Idle", "WarriorPlayer.png", 0, 3, 0.3f, true);
	Player->ChangeAnimation("Idle");
}




