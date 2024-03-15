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
	DialogText->SetText("머리가 아파 죽을 것 같아. 기억나는건 오직... \n하늘 위를 날아다니는 지팡이 든 해골뿐이야! 이 어둠은 그놈으로부터 생긴거야. 그놈이 주변의 \n모든 것을 파괴한 건가?");
}

void ADiaLog::StartNextText02()
{
	DialogText->SetText("가만히 있기만 해선 아무런 해답을 얻을 수 없겠군...");
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
	DialogText->SetText("분명 저기에 수풀이 있었던 기억이 있는데...\n내 기억이 맞긴 하는 건가? 아니면 그 슬라임의 기억인 건가?");
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
	TutorialText->SetText("화면 위쪽의 하루 진행도를 눈여겨 보십시오. 하루가 끝나면 새로운 적이 나타날 수 있습니다. \n\n- 게임 모드를 전환해 여정을 이어가십시오.(스페이스 바, 마우스 우클릭, 모드변경)");
}

void ADiaLog::TutorialGuideArrow03()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("여행, 전투, 그리고 대부분의 다른 행동은 자동으로 이루어집니다. 플레이어는 직접적으로 영향을 끼치지 않습니다. \n- 아무곳이나 눌러 계속 이어가십시오.");
}

void ADiaLog::TutorialGuideArrow04()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("당신에겐 소지품과 아이템 슬롯이 있습니다. 어떻게 해야 할 지는 알 것입니다. \n- 물품을 장비한 후 계속 이어가십시오.");
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
	TutorialText->SetText("적을 쓰러트리고 나온 카드를 사용해 지도에 다양한 사물을 배치할 수 있습니다. 계획 모드는 이 때 사용됩니다. \n- 카드를 적당한 장소에 둬서 땅을 기억 하십시오.");
}

void ADiaLog::TutorialGuideArrow06()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(false);
	RightArrow2->SetActive(false);
	TutorialText->SetText("잘 했습니다. \n- 이제 여정을 이어가십시오.");
}

void ADiaLog::TutorialGuideArrow07()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("이미 알아차리셨듯, 전투 중에 새로운 물품이나 카드를 얻을 수 있습니다. \n어떤 물품은 대부분의 카드처럼 특별한 능력을 가지고 있습니다. 물품이나 카드에 마우스를 올려놓으면 그 정보를 알 수 \n있습니다. \n\n- 새로운 무기를 장비한 후 새 카드를 지도 위에 배치하여 계속 이어 가십시오.");
}

void ADiaLog::TutorialGuideArrow08()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("특정 행동을 하게 되면 당장은 아니지만 나중에 필요할 자원을 얻을 수 있습니다. 지금 당장 설명하진 않을 것 입니다. \n- 게임 모드를 바꿔 여정을 이어가십시오. (스페이 바, 마우스 우클릭, 모드 변경");
}

void ADiaLog::TutorialGuideArrow09()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("이 게임은 길을 따라 여정을 반복하는 게임입니다. 언제 영웅이 야영지로 돌아갈지는 당신이 결정해야 합니다... \n물론 적들의 이빨과 발톱이 결정을 내려줄 수도 있지만요. \n거의 언제든 후퇴할 수 있지만, 특별한 애니메이션이 나오면 안전하게 후퇴할 수 있습니다. \n\n- 버튼을 눌러 야영지로 퇴각하십시오.");
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
	DialogText->SetText("여긴 어디지? 이 길 말고는 아무것도 안 보여.");
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
	TutorialText->SetText("모험 (지도위를 여행) 모드와 계획 (멈춤) 모드 사이를 전환하려면 스위치를 누르거나, 우클릭이나 스페이스바를 누르십시오. \n- 게임 모드를 바꿔 여정을 이어가십시오.");
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