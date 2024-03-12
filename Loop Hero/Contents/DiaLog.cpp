#include "DiaLog.h"
#include <EnginePlatform/EngineInput.h>

ADiaLog::ADiaLog()
{
}

ADiaLog::~ADiaLog()
{
}

void ADiaLog::DialogAnimation(float _DeltaTime)
{
	DiaLogMove += _DeltaTime / 1.0f;
	FVector DialogCharacterStartPos = { 100, 575 };
	FVector DialogCharacterEndPos = { 150, 575 };
	FVector DialogCharacterMovePos = float4::LerpClamp(DialogCharacterStartPos, DialogCharacterEndPos, DiaLogMove);
	DialogCharacter->SetTransform({ {DialogCharacterMovePos.X, DialogCharacterMovePos.Y}, {300, 300} });

	FVector DialogBoxStartPos = { 650, 650 };
	FVector DialogBoxEndPos = { 650, 600 };
	FVector DialogBoxMovePos = float4::LerpClamp(DialogBoxStartPos, DialogBoxEndPos, DiaLogMove);
	DialogBox->SetTransform({ {DialogBoxMovePos.X, DialogBoxMovePos.Y}, {800, 250} });
}

void ADiaLog::StartNextText(int _DialogCount)
{

	if (1 == _DialogCount)
	{
		DialogText->SetText("�Ӹ��� ���� ���� �� ����. ��ﳪ�°� ����... \n�ϴ� ���� ���ƴٴϴ� ������ �� �ذ���̾�! �� ����� �׳����κ��� ����ž�. �׳��� �ֺ��� \n��� ���� �ı��� �ǰ�?");

	}
	else if (2 == _DialogCount)
	{
		DialogText->SetText("������ �ֱ⸸ �ؼ� �ƹ��� �ش��� ���� �� ���ڱ�...");
		DiaProgressbar->SetImage("s_dia_lastworddark_1.png");
	}

	return;
}

void ADiaLog::Text01()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetText("�ذ� ���� ���� �� ���� ã�� �� ������ ���ھ�... ���� �� ������ ���� �����Ѵٸ� ������.");
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
}

void ADiaLog::ADiaLog::BeginPlay()
{
	AActor::BeginPlay();
	DialogCharacter = CreateImageRenderer();
	DialogCharacter->SetImage("s_dia_PortrHero_rytsar.png");
	DialogCharacter->SetOrder(15);
	DialogCharacter->SetActive(true);
	DialogCharacter->SetTransform({ { 150, 575 }, { 300, 300} });

	DialogBox = CreateImageRenderer();
	DialogBox->SetImage("s_dia_plashka.png");
	DialogBox->SetOrder(14);
	DialogBox->SetActive(true);
	DialogBox->SetTransform({ { 650, 600 }, { 800, 250} });

	DialogText = CreateImageRenderer();
	DialogText->SetOrder(15);
	DialogText->SetText("���� �����? �� �� ����� �ƹ��͵� �� ����.");
	DialogText->SetTextColor(Color8Bit::White);
	DialogText->SetTextSortOption(Gdiplus::StringAlignmentNear, Gdiplus::StringAlignmentNear);
	DialogText->SetTextSize(17);
	DialogText->SetActive(false);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });

	DiaProgressbar = CreateImageRenderer();
	DiaProgressbar->SetImage("s_dia_lastworddark_0.png");
	DiaProgressbar->SetOrder(15);
	DiaProgressbar->SetActive(false);
	DiaProgressbar->SetTransform({ { 650, 500 }, { 30, 30} });

	DialogBackground = CreateImageRenderer();
	DialogBackground->SetImage("TutorialStartBackGround.png");
	DialogBackground->SetOrder(13);
	DialogBackground->SetAlpha(0.5);
	DialogBackground->SetTransform({ { 640, 360 }, { 1280, 720} });
}

void ADiaLog::ADiaLog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	DialogAnimation(_DeltaTime);

	DiaProgressbarTime -= _DeltaTime;
	if (0 > DiaProgressbarTime && 3 > DialogCount)
	{
		DiaProgressbar->SetActive(true);
		DialogText->SetActive(true);
	}

	if (UEngineInput::IsDown(VK_LBUTTON))
	{
		++DialogCount;
		StartNextText(DialogCount);
	}
}