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
	PlayerRender();

}

void ATutorialRander::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

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

void ATutorialRander::PlayerRender()
{
	UImageRenderer* Player = CreateImageRenderer();
	Player->SetImage("WarriorPlayer.png");
	Player->SetTransform({ {50,-100}, {100, 100} });
	Player->CreateAnimation("Idle", "WarriorPlayer.png", 0, 3, 0.3f, true);
	Player->ChangeAnimation("Idle");
}




