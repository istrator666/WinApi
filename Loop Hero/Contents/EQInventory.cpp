#include "EQInventory.h"
#include "Enum.h"

EQInventory::EQInventory()
{
}

EQInventory::~EQInventory()
{
}

void EQInventory::AEQInventoryUI::BeginPlay()
{
	AActor::BeginPlay();
	EQInventoryUI();
}

void EQInventory::AEQInventoryUI::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (nullptr != EQInventoryIcon)
	{
		Movetime += _DeltaTime * 2.0f;

		FVector CurPos = FVector::LerpClamp(StartPosition, EndPosition, Movetime);
		EQInventoryIcon->SetPosition(CurPos);
		EQInventoryIconCollision->SetPosition(CurPos);
	}


	if (nullptr != SelectEQInventoryIcon)
	{
		SelectEQInventoryIcon->SetPosition(GEngine->MainWindow.GetMousePosition());
		SelectEQInventoryIconCollision->SetPosition(GEngine->MainWindow.GetMousePosition());

		if (UEngineInput::IsUp(VK_LBUTTON))
		{
			SelectEQInventoryIcon = nullptr;
			SelectEQInventoryIconCollision = nullptr;
		}
	}
}

void EQInventory::AEQInventoryUI::EQInventoryUI()
{
	EQInventoryRender = CreateImageRenderer();
	EQInventoryRender->SetImage("Equipment.png");
	EQInventoryRender->SetOrder(5);
	EQInventoryRender->SetTransform({ {1130, 360}, {295,730} });

	EQIcon = CreateImageRenderer();
	EQIcon->SetImage("Weapons.png");
	EQIcon->CreateAnimation("Weapons", "Weapons.png", 0, 0, 0.3f, false);
	EQIcon->ChangeAnimation("Weapons");
	EQIcon->SetOrder(9);
	EQIcon->SetActive(false);

	RetreatRender = CreateImageRenderer();
	RetreatRender->SetImage("s_pobeg.png");
	RetreatRender->CreateAnimation("Retreat", "s_pobeg.png", 0, 9, 0.1f, true);
	RetreatRender->ChangeAnimation("Retreat");
	RetreatRender->SetOrder(10);
	RetreatRender->SetActive(false);
	RetreatRender->SetTransform({ {1023, 688}, {250,250} });
}

void EQInventory::AEQInventoryUI::TutorialAddEQ(FVector _MonsterPosition)
{
	EQInventoryIcon = CreateImageRenderer();
	EQInventoryIcon->SetImage("Weapons.png");
	EQInventoryIcon->CreateAnimation("Weapons", "Weapons.png", 0, 0, 0.3f, false);
	EQInventoryIcon->ChangeAnimation("Weapons");
	EQInventoryIcon->SetOrder(9);

	EQInventoryIconCollision = CreateCollision();
	EQInventoryIconCollision->SetScale({ 50, 50 });
	EQInventoryIconCollision->SetColType(ECollisionType::Rect);

	EQInventoryIcon->SetTransform({ _MonsterPosition, {200,200} });
	EQInventoryIconCollision->SetPosition(_MonsterPosition);

	StartPosition = { _MonsterPosition };
	EndPosition = { 1088, 280 };
}

bool EQInventory::AEQInventoryUI::TutorialEQSetup()
{
	if (1.0f <= Movetime)
	{
		std::vector<UCollision*> Result;
		if (true == EQInventoryIconCollision->CollisionCheck(ECollision::Mouse, Result) && UEngineInput::IsDown(VK_LBUTTON))
		{
			SelectEQInventoryIcon = EQInventoryIcon;
			SelectEQInventoryIconCollision = EQInventoryIconCollision;

			return true;
		}
	}

	return false;
}

bool EQInventory::AEQInventoryUI::TutorialEQSetUPComplete()
{
	if (nullptr != SelectEQInventoryIcon && UEngineInput::IsUp(VK_LBUTTON))
	{
		int X = static_cast<int>(GEngine->MainWindow.GetMousePosition().X);
		int Y = static_cast<int>(GEngine->MainWindow.GetMousePosition().Y);

		if (1063 <= X && 1113 >= X && 51 <= Y && 101 >= Y)
		{
			//인벤토리 무기칸 좌표 얻어서 이미지 넣기
				// { 1088, 76 };

			EQIcon->SetTransform({ { 1088, 76 }, {200, 200} });
			EQIcon->SetActive(true);

			SelectEQInventoryIcon->Destroy();
			SelectEQInventoryIconCollision->Destroy();
			SelectEQInventoryIcon = nullptr;
			SelectEQInventoryIconCollision = nullptr;

			return true;
		}
	}

	return false;
}

void EQInventory::AEQInventoryUI::Retreat()
{
	RetreatRender->SetActive(true);

}
