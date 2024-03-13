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
		DialogText->SetText("머리가 아파 죽을 것 같아. 기억나는건 오직... \n하늘 위를 날아다니는 지팡이 든 해골뿐이야! 이 어둠은 그놈으로부터 생긴거야. 그놈이 주변의 \n모든 것을 파괴한 건가?");

	}
	else if (2 == _DialogCount)
	{
		DialogText->SetText("가만히 있기만 해선 아무런 해답을 얻을 수 없겠군...");
		DiaProgressbar->SetImage("s_dia_lastworddark_1.png");
	}

	return;
}

void ADiaLog::Text01()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetText("해가 지기 전에 쉴 곳을 찾을 수 있으면 좋겠어... 물론 밤 같은게 아직 존재한다면 말이지.");
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
		DialogText->SetText("살아있는 슬라임 한 마리군. 꽤나 골칫거리인걸. 이놈들은 뭐든지 소화시켜버리니까.");
	}
	if (1 == TextCount)
	{
		DialogText->SetText("어! 이 생물이 기억났어! 어쩌면 내 기억을 되살리면 모든 게 정상으로 돌아갈지도 몰라");
	}
}

void ADiaLog::Text03()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("맨손으로 싸우는 게 이렇게 힘들 줄이야. 아직 완전히 소화되지 않은 무기가 있었던 거 같은데...");

}

void ADiaLog::Text04()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("분명 저기에 수풀이 있었던 기억이 있는데... 내 기억이 맞긴 하는 건가? 아니면 그 슬라임의 기억인 건가?");
}

void ADiaLog::Text05()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("숲의 랫울프군.");
	//DialogText->SetText("역시 기억에 문제가 있군. 스트레스도 받은데다가 화려한 것도 보고 흥분한 상태가 되니 \n악몽마냥 다 잊어버린 것 같아...");
	//DialogText->SetText("아니면 그냥 나쁜... 망할! 아무도 안 듣고 있어서 다행이군.");
}

void ADiaLog::Text06()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("좋아.저기엔 산이 있었고, 여기엔 숲이 있군. 세상이 완전히 달라졌어. 배낭에 있는 나뭇가지와 \n돌멩이가 확실한 그 증거야.");
}

void ADiaLog::Text07()
{
	DialogCharacter->SetActive(true);
	DialogBox->SetActive(true);
	DialogText->SetActive(true);
	DialogText->SetTransform({ { 280, 540 }, { 0, 0} });
	DialogText->SetText("좀 쉬어야 할 것 같은데.");
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
	DialogText->SetText("여긴 어디지? 이 길 말고는 아무것도 안 보여.");
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