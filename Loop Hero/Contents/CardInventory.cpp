#include "CardInventory.h"
#include "MouseFunction.h"
#include <thread>
#include "Enum.h"
#include "TutorialRender.h"

ACardInventory::ACardInventory()
{
}

ACardInventory::~ACardInventory()
{
}

void ACardInventory::AddCard(int _Card, FVector _MonsterPosition)
{
	for (size_t i = 0; i < _Card; i++)
	{
		Node CardNode;
		CardNode.CardRander = CreateImageRenderer();
		CardNode.CardRander->SetImage("Cards.png");
		CardNode.CardRander->SetOrder(9);
		CardNode.CardRander->CreateAnimation("Card", "Cards.png", 3, 3, 0.3f, false);
		CardNode.CardRander->ChangeAnimation("Card");
		CardNode.CardRander->SetTransform({ _MonsterPosition, {250,250} });
		CardNode.StartPosition = _MonsterPosition;
		CardList.push_back(CardNode);
	}

	if (CardList.size() > 13)
	{
		size_t StartSize = CardList.size();
		for (size_t i = 0; i < StartSize - 13; i++)
		{
			Node& DeleteNode = CardList.front();

			DeleteNode.StartPosition = DeleteNode.CardRander->GetPosition();
			DeleteNode.EndPosition = { DeleteNode.StartPosition.X, DeleteNode.StartPosition.Y - 100 };
			DeleteNode.Movetime = 0.0f;
			DeleteList.push_back(DeleteNode);
			CardList.erase(CardList.begin());
		}
	}

	int Count = 0;
	for (Node& CurNode : CardList)
	{
		CurNode.EndPosition = FVector(75 * Count, 700);
		++Count;
	}
}

void ACardInventory::TutorialAddCard(int _Card, FVector _MonsterPosition)
{
	for (size_t i = 0; i < _Card; i++)
	{
		if (2 < TutorialCardNumber)
		{
			TutorialCardNumber = 2;
		}

		Node CardNode;
		CardNode.CardRander = CreateImageRenderer();
		CardNode.CardCollision = CreateCollision(ECollision::Card);
		CardNode.CardCollision->SetScale({ 80, 120 });
		CardNode.CardCollision->SetColType(ECollisionType::Rect);
		CardNode.CardTileNumber = TutorialCardNumber;
		CardNode.CardRander->SetImage("TutorialCard", TutorialCardNumber++);
		CardNode.CardRander->SetOrder(9);
		CardNode.CardRander->SetTransform({ _MonsterPosition, {175,175} });
		CardNode.StartPosition = _MonsterPosition;
		CardList.push_back(CardNode);
	}

	size_t StartSize = CardList.size();

	if (StartSize > 13)
	{
		for (size_t i = 0; i < StartSize - 13; i++)
		{
			Node& DeleteNode = CardList.front();

			DeleteNode.StartPosition = DeleteNode.CardRander->GetPosition();
			DeleteNode.EndPosition = { DeleteNode.StartPosition.X, DeleteNode.StartPosition.Y - 100 };
			DeleteNode.Movetime = 0.0f;
			DeleteList.push_back(DeleteNode);
			CardList.erase(CardList.begin());
		}
	}


	int Count = 0;
	for (Node& CurNode : CardList)
	{
		CurNode.EndPosition = FVector(75 * Count, 670);
		++Count;
	}
}

int ACardInventory::CardListSize()
{
	return static_cast<int>(CardList.size());
}

bool ACardInventory::TutorialCardSetUp(bool _Check)
{

	IsTutorialCardSetUp = _Check;

	if (nullptr != SelectNode)
	{
		return true;
	}

	return false;
}

bool ACardInventory::TutorialCardComplete()
{
	//들고 있는 카드를 
	// 놓았을 때, 
	// 그 자리 타일 이미지 변경
	if (nullptr != Map && nullptr != SelectNode && UEngineInput::IsUp(VK_LBUTTON) && 25 < SelectNode->CardRander->GetPosition().X && 600 > SelectNode->CardCollision->GetPosition().Y)
	{
		// 마우스 좌표를 얻어서 50으로 나눈 후 타일에 들어가는지 확인
		int X = static_cast<int>(GEngine->MainWindow.GetMousePosition().X / 50);
		int Y = static_cast<int>(GEngine->MainWindow.GetMousePosition().Y / 50);

		if (6 == Y && 8 == X)
		{
			Map->TileList[Y][X]->SetImage("Tiles", SelectNode->CardTileNumber);
			SelectNode->CardRander->Destroy();
			SelectNode->CardCollision->Destroy();

			std::_List_iterator<std::_List_val<std::_List_simple_types<Node>>> it = std::find_if(CardList.begin(), CardList.end(), [this](const Node& node) {
				return &node == SelectNode;
				});
			if (it != CardList.end())
			{
				CardList.erase(it);
			}

			SelectNode = nullptr;

			return true;
		}
	}

	return false;
}

void ACardInventory::ACardInventory::BeginPlay()
{
	AActor::BeginPlay();
}

void ACardInventory::ACardInventory::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	for (Node& CurNode : CardList)
	{
		CurNode.Movetime += _DeltaTime * 2.0f;

		FVector CurPos = FVector::LerpClamp(CurNode.StartPosition, CurNode.EndPosition, CurNode.Movetime);

		CurNode.CardRander->SetPosition(CurPos);
		CurNode.CardCollision->SetPosition(CurPos);

		if (nullptr != SelectNode)
		{
			continue;
		}

		if (1.0f <= CurNode.Movetime)
		{
			std::vector<UCollision*> Result;
			FVector NextPos;
			if (true == CurNode.CardCollision->CollisionCheck(ECollision::Mouse, Result) && UEngineInput::IsDown(VK_LBUTTON) && true == IsTutorialCardSetUp)
			{
				SelectNode = &CurNode;
			}
		}
	}

	if (nullptr != SelectNode)
	{
		SelectNode->CardRander->SetPosition(GEngine->MainWindow.GetMousePosition());
		SelectNode->CardCollision->SetPosition(GEngine->MainWindow.GetMousePosition());

		if (25 < SelectNode->CardRander->GetPosition().X && 600 > SelectNode->CardCollision->GetPosition().Y)
		{
			SelectNode->CardRander->SetImage("Tiles", SelectNode->CardTileNumber);
			SelectNode->CardRander->SetScale({ 50, 50 });
			SelectNode->CardCollision->SetScale({ 50, 50 });
		}
		else
		{
			SelectNode->CardRander->SetImage("TutorialCard", SelectNode->CardTileNumber);
			SelectNode->CardRander->SetScale({ 175,175 });
			SelectNode->CardCollision->SetScale({ 80, 120 });
		}

		if (UEngineInput::IsUp(VK_LBUTTON))
		{
			SelectNode->CardRander->SetImage("TutorialCard", SelectNode->CardTileNumber);
			SelectNode->CardRander->SetScale({ 175,175 });
			SelectNode->CardCollision->SetScale({ 80, 120 });
			SelectNode = nullptr;
		}
	}

	std::list<Node>::iterator StartIter = DeleteList.begin();
	std::list<Node>::iterator EndIter = DeleteList.end();

	for (; StartIter != EndIter; )
	{
		Node& CurNode = StartIter.operator*();

		if (CurNode.Movetime < 1.0f)
		{
			CurNode.Movetime += _DeltaTime * 2.0f;

			FVector CurPos = FVector::LerpClamp(CurNode.StartPosition, CurNode.EndPosition, CurNode.Movetime);
			CurNode.CardRander->SetPosition(CurPos);

			++StartIter;
			continue;
		}

		CurNode.CardRander->Destroy();

		StartIter = DeleteList.erase(StartIter);
	}

	//GamePause();
}

//void ACardInventory::GamePause()
//{
//	FVector PosCheck = UMouseFunction::GetMousePos();
//
//	if ((0 <= PosCheck.X && 975 >= PosCheck.X) && (650 <= PosCheck.Y && 800 >= PosCheck.Y))
//	{
//		if (!IsPause)
//		{
//			for (std::list<Node>::iterator CurrentNode = CardList.begin(); CurrentNode != CardList.end(); ++CurrentNode)
//			{
//				int CurPosX = static_cast<int>(CurrentNode->CardRander->GetTransform().GetPosition().X);
//				int CurPosY = -30;
//				CurrentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {175,175} });
//			}
//			IsPause = true;
//		}
//	}
//	else
//	{
//		if (IsPause)
//		{
//			for (std::list<Node>::iterator CurrentNode = CardList.begin(); CurrentNode != CardList.end(); ++CurrentNode)
//			{
//				int CurPosX = static_cast<int>(CurrentNode->CardRander->GetTransform().GetPosition().X);
//				int CurPosY = 0;
//				CurrentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {175,175} });
//			}
//			IsPause = false;
//		}
//	}
//}
