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


	//if (nullptr != Map && nullptr != SelectNode && UEngineInput::IsUp(VK_LBUTTON) && 25 < SelectNode->CardRander->GetPosition().X && 600 > SelectNode->CardCollision->GetPosition().Y)
	//{
	//	// 마우스 좌표를 얻어서 50으로 나눈 후 타일에 들어가는지 확인
	//	int X = static_cast<int>(GEngine->MainWindow.GetMousePosition().X / 50);
	//	int Y = static_cast<int>(GEngine->MainWindow.GetMousePosition().Y / 50);

	//	if (6 == Y && 8 == X)
	//	{
	//		Map->TileList[Y][X]->SetImage("Tiles", SelectNode->CardTileNumber);
	//		SelectNode->CardRander->Destroy();
	//		SelectNode->CardCollision->Destroy();
	//		SelectNode = nullptr;
	//	}
	//}

	if (nullptr != SelectEQInventoryIcon && UEngineInput::IsUp(VK_LBUTTON))
	{
		int X = static_cast<int>(GEngine->MainWindow.GetMousePosition().X / 50);
		int Y = static_cast<int>(GEngine->MainWindow.GetMousePosition().Y / 50);


		if (6 == Y && 8 == X)
		{
			//인벤토리 무기칸 좌표 얻어서 이미지 넣기

			SelectEQInventoryIcon->Destroy();
			SelectEQInventoryIconCollision->Destroy();
			SelectEQInventoryIcon = nullptr;
			SelectEQInventoryIconCollision = nullptr;
		}
	}

	if (nullptr != EQInventoryIcon)
	{
		Movetime += _DeltaTime * 2.0f;

		FVector CurPos = FVector::LerpClamp(StartPosition, EndPosition, Movetime);
		EQInventoryIcon->SetPosition(CurPos);
		EQInventoryIconCollision->SetPosition(CurPos);
	}

	if (1.0f <= Movetime)
	{
		std::vector<UCollision*> Result;
		if (true == EQInventoryIconCollision->CollisionCheck(ECollision::Mouse, Result) && UEngineInput::IsDown(VK_LBUTTON))
		{
			SelectEQInventoryIcon = EQInventoryIcon;
			SelectEQInventoryIconCollision = EQInventoryIconCollision;
		}
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


	//EQInventoryIcon->SetTransform({ {-42, -80}, {200,200} });
	//EQInventoryIcon->SetTransform({ {-42, -284}, {200,200} });
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
	// { 1088, 76 };
}
