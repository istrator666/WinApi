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
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);

	DiaLogMove += _DeltaTime / 1.0f;
	FVector DialogCharacterStartPos = { 100, 575 };
	FVector DialogCharacterEndPos = { 150, 575 };
	FVector DialogCharacterMovePos = float4::LerpClamp(DialogCharacterStartPos, DialogCharacterEndPos, DiaLogMove);
	DialogCharacter->SetTransform({ {DialogCharacterMovePos.X, DialogCharacterMovePos.Y}, {300, 300} });

	FVector DialogBoxStartPos = { 650, 650 };
	FVector DialogBoxEndPos = { 650, 600 };
	FVector DialogBoxMovePos = float4::LerpClamp(DialogBoxStartPos, DialogBoxEndPos, DiaLogMove);
	DialogBox->SetTransform({ {DialogBoxMovePos.X, DialogBoxMovePos.Y}, {800, 250} });

	DiaProgressbarTime -= _DeltaTime;
	if (0 > DiaProgressbarTime)
	{
		DialogText->SetActive(true);
	}
}

void ADiaLog::StartNextText01()
{
	DialogText->SetText("�Ӹ��� ���� ���� �� ����. ��ﳪ�°� ����... \n�ϴ� ���� ���ƴٴϴ� ������ �� �ذ���̾�! �� ����� �׳����κ��� ����ž�. �׳��� �ֺ��� \n��� ���� �ı��� �ǰ�?");
}

void ADiaLog::StartNextText02()
{
	DialogText->SetText("������ �ֱ⸸ �ؼ� �ƹ��� �ش��� ���� �� ���ڱ�...");
}

void ADiaLog::Text01()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetText("�ذ� ���� ���� �� ���� ã�� �� ������ ���ھ�... ���� �� ������ ���� �����Ѵٸ� ������.");
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
}

void ADiaLog::Text02()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });

	if (0 == TextCount)
	{
		DialogText->SetText("����ִ� ������ �� ������. �ϳ� ��ĩ�Ÿ��ΰ�. �̳���� ������ ��ȭ���ѹ����ϱ�.");
	}
	if (1 == TextCount)
	{
		DialogText->SetText("��! �� ������ ��ﳵ��! ��¼�� �� ����� �ǻ츮�� ��� �� �������� ���ư����� ����");
	}
}

void ADiaLog::Text03()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("�Ǽ����� �ο�� �� �̷��� ���� ���̾�. ���� ������ ��ȭ���� ���� ���Ⱑ �־��� �� ������...");

}

void ADiaLog::Text04()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("�и� ���⿡ ��Ǯ�� �־��� ����� �ִµ�...\n�� ����� �±� �ϴ� �ǰ�? �ƴϸ� �� �������� ����� �ǰ�?");
}

void ADiaLog::Text05()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("���� ��������.");
	//DialogText->SetText("���� ��￡ ������ �ֱ�. ��Ʈ������ �������ٰ� ȭ���� �͵� ���� ����� ���°� �Ǵ� \n�Ǹ����� �� �ؾ���� �� ����...");
	//DialogText->SetText("�ƴϸ� �׳� ����... ����! �ƹ��� �� ��� �־ �����̱�.");
}

void ADiaLog::Text06()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("����.���⿣ ���� �־���, ���⿣ ���� �ֱ�. ������ ������ �޶�����. �賶�� �ִ� ���������� \n�����̰� Ȯ���� �� ���ž�.");
}

void ADiaLog::Text07()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("�� ����� �� �� ������.");
}

void ADiaLog::TextEnd()
{
	DialogCharacter->SetActive(false);
	DialogBox->SetActive(false);
	DialogText->SetActive(false);
}

void ADiaLog::TutorialGuideArrow01()
{
	DialogCharacter->SetActive(false);
	DialogBox->SetActive(false);
	DialogText->SetActive(false);
	UPArrow->SetActive(true);
	TutorialText->SetActive(true);
}

void ADiaLog::TutorialGuideArrow02()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("ȭ�� ������ �Ϸ� ���൵�� ������ ���ʽÿ�. �Ϸ簡 ������ ���ο� ���� ��Ÿ�� �� �ֽ��ϴ�. \n\n- ���� ��带 ��ȯ�� ������ �̾�ʽÿ�.(�����̽� ��, ���콺 ��Ŭ��, ��庯��)");
}

void ADiaLog::TutorialGuideArrow03()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("����, ����, �׸��� ��κ��� �ٸ� �ൿ�� �ڵ����� �̷�����ϴ�. �÷��̾�� ���������� ������ ��ġ�� �ʽ��ϴ�. \n- �ƹ����̳� ���� ��� �̾�ʽÿ�.");
}

void ADiaLog::TutorialGuideArrow04()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("��ſ��� ����ǰ�� ������ ������ �ֽ��ϴ�. ��� �ؾ� �� ���� �� ���Դϴ�. \n- ��ǰ�� ����� �� ��� �̾�ʽÿ�.");
}

void ADiaLog::TutorialGuideArrow05()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow->SetPosition({370, 320});
	RightArrow2->SetActive(true);
	RightArrow2->SetPosition({ 120, 670 });
	RightArrow2->SetImage("Left.png");
	RightArrow2->ChangeAnimation("Idle1");
	TutorialText->SetText("���� ����Ʈ���� ���� ī�带 ����� ������ �پ��� �繰�� ��ġ�� �� �ֽ��ϴ�. ��ȹ ���� �� �� ���˴ϴ�. \n- ī�带 ������ ��ҿ� �ּ� ���� ��� �Ͻʽÿ�.");
}

void ADiaLog::TutorialGuideArrow06()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(false);
	RightArrow2->SetActive(false);
	TutorialText->SetText("�� �߽��ϴ�. \n- ���� ������ �̾�ʽÿ�.");
}

void ADiaLog::TutorialGuideArrow07()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("�̹� �˾������̵�, ���� �߿� ���ο� ��ǰ�̳� ī�带 ���� �� �ֽ��ϴ�. \n� ��ǰ�� ��κ��� ī��ó�� Ư���� �ɷ��� ������ �ֽ��ϴ�. ��ǰ�̳� ī�忡 ���콺�� �÷������� �� ������ �� �� \n�ֽ��ϴ�. \n\n- ���ο� ���⸦ ����� �� �� ī�带 ���� ���� ��ġ�Ͽ� ��� �̾� ���ʽÿ�.");
}

void ADiaLog::TutorialGuideArrow08()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("Ư�� �ൿ�� �ϰ� �Ǹ� ������ �ƴ����� ���߿� �ʿ��� �ڿ��� ���� �� �ֽ��ϴ�. ���� ���� �������� ���� �� �Դϴ�. \n- ���� ��带 �ٲ� ������ �̾�ʽÿ�. (������ ��, ���콺 ��Ŭ��, ��� ����");
}

void ADiaLog::TutorialGuideArrow09()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("�� ������ ���� ���� ������ �ݺ��ϴ� �����Դϴ�. ���� ������ �߿����� ���ư����� ����� �����ؾ� �մϴ�... \n���� ������ �̻��� ������ ������ ������ ���� ��������. \n���� ������ ������ �� ������, Ư���� �ִϸ��̼��� ������ �����ϰ� ������ �� �ֽ��ϴ�. \n\n- ��ư�� ���� �߿����� ���Ͻʽÿ�.");
}


void ADiaLog::TutorialGuideArrowEnd()
{
	UPArrow->SetActive(false);
	TutorialText->SetActive(false);
	RightArrow->SetActive(false);
	RightArrow2->SetActive(false);
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

	DialogBackground = CreateImageRenderer();
	DialogBackground->SetImage("TutorialStartBackGround.png");
	DialogBackground->SetOrder(13);
	DialogBackground->SetAlpha(0.5);
	DialogBackground->SetTransform({ { 640, 360 }, { 1280, 720} });

	UPArrow = CreateImageRenderer();
	UPArrow->SetImage("Up.png");
	UPArrow->SetOrder(15);
	UPArrow->SetTransform({ {565, 90}, {250,250} });
	UPArrow->CreateAnimation("Idle", "Up.png", 0, 36, 0.25f, true);
	UPArrow->ChangeAnimation("Idle");
	UPArrow->SetActive(false);

	RightArrow = CreateImageRenderer();
	RightArrow->SetImage("Right.png");
	RightArrow->SetOrder(15);
	RightArrow->SetTransform({ {1010, 280}, {250,250} });
	RightArrow->CreateAnimation("Idle", "Right.png", 0, 36, 0.25f, true);
	RightArrow->ChangeAnimation("Idle");
	RightArrow->SetActive(false);

	RightArrow2 = CreateImageRenderer();
	RightArrow2->SetImage("Right.png");
	RightArrow2->SetOrder(15);
	RightArrow2->SetTransform({ {1010, 80}, {250,250} });
	RightArrow2->CreateAnimation("Idle", "Right.png", 0, 36, 0.25f, true);
	RightArrow2->CreateAnimation("Idle1", "Left.png", 0, 0, 0.25f, true);
	RightArrow2->ChangeAnimation("Idle");
	RightArrow2->SetActive(false);

	TutorialText = CreateImageRenderer();
	TutorialText->SetText("���� (�������� ����) ���� ��ȹ (����) ��� ���̸� ��ȯ�Ϸ��� ����ġ�� �����ų�, ��Ŭ���̳� �����̽��ٸ� �����ʽÿ�. \n- ���� ��带 �ٲ� ������ �̾�ʽÿ�.");
	TutorialText->SetTextColor(Color8Bit::White);
	TutorialText->SetTextSize(17);
	TutorialText->SetTextSortOption(Gdiplus::StringAlignmentNear, Gdiplus::StringAlignmentNear);
	TutorialText->SetOrder(15);
	TutorialText->SetTransform({ {25, 500}, {200,200} });
	TutorialText->SetActive(false);
}

void ADiaLog::ADiaLog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}