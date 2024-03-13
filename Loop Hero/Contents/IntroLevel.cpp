#include "IntroLevel.h"

#include "EngineCore/EngineCore.h"

UIntroLevel::UIntroLevel()
{
}

UIntroLevel::~UIntroLevel()
{
}

void UIntroLevel::BeginPlay()
{
	ULevel::BeginPlay();

	Intro = SpawnActor<AIntroRender>();
}

void UIntroLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	//if (UEngineInput::IsDown('P'))
	//{
	//	GEngine->ChangeLevel("StageLevel");
	//}

	StateUpdate(_DeltaTime);
}

void UIntroLevel::ChangeState(IntroState _State)
{
	switch (_State)
	{
	case IntroState::Idle:
		break;
	case IntroState::Next:
		Next();
		break;
	case IntroState::Prev:
		Prev();
		break;
	case IntroState::Skip:
		Skip();
		break;
	default:
		break;
	}
}

void UIntroLevel::StateUpdate(float _DeltaTime)
{
	switch (CurState)
	{
	case IntroState::Idle:
		Idle();
		break;
	case IntroState::Next:
		break;
	case IntroState::Prev:
		break;
	case IntroState::Skip:
		Skip();
		break;
	default:
		break;
	}
}

void UIntroLevel::Idle()
{
	if (7 < Intro->ImageNumber && 105 >Intro->ImageNumber)
	{
		Intro->IntroBackButton->SetActive(true);
		Intro->IntroSkipButton->SetActive(true);
	}
	else
	{
		Intro->IntroBackButton->SetActive(false);
		Intro->IntroSkipButton->SetActive(false);
	}

	ChangeState(IntroState::Skip);

	if ((70 <= Intro->PosCheck.X && 150 >= Intro->PosCheck.X) && (620 <= Intro->PosCheck.Y && 680 >= Intro->PosCheck.Y))
	{
		Intro->IntroBackButton->SetImage("s_dia_back_button_1.png");
		if (UEngineInput::IsDown(VK_LBUTTON))
		{
			ChangeState(IntroState::Prev);
		}
	}
	else if (UEngineInput::IsDown(VK_LBUTTON))
	{
		ChangeState(IntroState::Next);
	}
	else if ((200 <= Intro->PosCheck.X && 270 >= Intro->PosCheck.X) && (620 <= Intro->PosCheck.Y && 680 >= Intro->PosCheck.Y))
	{
		Intro->IntroSkipButton->SetImage("s_dia_skip_button_1.png");
		if (UEngineInput::IsDown(VK_LBUTTON))
		{
		ChangeState(IntroState::Skip);
		}
	}
	else
	{
		Intro->IntroBackButton->SetImage("s_dia_back_button_0.png");
		Intro->IntroSkipButton->SetImage("s_dia_skip_button_0.png");
	}
}

void UIntroLevel::Next()
{
	if (114 < Intro->ImageNumber)
	{
		Intro->IntroBackButton->SetActive(false);
		Intro->IntroSkipButton->SetActive(false);
		GEngine->ChangeLevel("Tutorial");
	}
	else
	{
		++Intro->ImageNumber;
		ChangeState(IntroState::Idle);
	}
}

void UIntroLevel::Prev()
{
	Intro->IntroBackButton->SetImage("s_dia_back_button_2.png");

	if (1 > Intro->ImageNumber)
	{
		ChangeState(IntroState::Idle);
		return;
	}
	else
	{
		--Intro->ImageNumber;
		ChangeState(IntroState::Idle);
	}
}

void UIntroLevel::Skip()
{
	Intro->IntroSkipButton->SetImage("s_dia_skip_button_2.png");

	if (114 < Intro->ImageNumber)
	{
		GEngine->ChangeLevel("Tutorial");
	}
	else
	{
		++Intro->ImageNumber;
	}
}