#include "DiaLog.h"

ADiaLog::ADiaLog()
{
}

ADiaLog::~ADiaLog()
{
}

void ADiaLog::DialogPlayer()
{

}

void ADiaLog::DialogBoxFuntion()
{

}

void ADiaLog::ADiaLog::BeginPlay()
{
	AActor::BeginPlay();
	DialogCharacter = CreateImageRenderer();
	DialogCharacter->SetImage("s_dia_PortrHero_rytsar.png");
	DialogCharacter->SetOrder(10);
	DialogCharacter->SetActive(true);
	DialogCharacter->SetTransform({ { 150, 575 }, { 300, 300} });

	DialogBox = CreateImageRenderer();
	DialogBox->SetImage("s_dia_plashka.png");
	DialogBox->SetOrder(9);
	DialogBox->SetActive(true);
	DialogBox->SetTransform({ { 650, 600 }, { 800, 250} });

	DiaProgressbar = CreateImageRenderer();
	DiaProgressbar->SetImage("s_dia_lastworddark_0.png");
	DiaProgressbar->SetOrder(10);
	DiaProgressbar->SetActive(true);
	DiaProgressbar->SetTransform({ { 650, 500 }, { 30, 30} });
}

void ADiaLog::ADiaLog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}