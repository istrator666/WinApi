#include "CardInventory.h"
#include "MouseFunction.h"
#include <thread>
#include "Enum.h"

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
            DeleteNode.EndPosition = { DeleteNode.StartPosition.X, DeleteNode.StartPosition.Y -100};
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
        Node CardNode;
        CardNode.CardRander = CreateImageRenderer();
        CardNode.CardCollision = CreateCollision(ECollision::Card);
        CardNode.CardCollision->SetScale({80, 120});
        CardNode.CardCollision->SetColType(ECollisionType::Rect);
        CardNode.CardRander->SetImage("TutorialCard01.png");
        CardNode.CardRander->SetOrder(9);
        CardNode.CardRander->SetTransform({ _MonsterPosition, {175,175} });
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
        CurNode.EndPosition = FVector(75 * Count, 670);
        ++Count;
    }
}

int ACardInventory::CardListSize()
{
    return static_cast<int>(CardList.size());
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

void ACardInventory::GamePause()
{
    FVector PosCheck = UMouseFunction::GetMousePos();

    if ((0 <= PosCheck.X && 975 >= PosCheck.X) && (650 <= PosCheck.Y && 800 >= PosCheck.Y))
    {
        if (!IsPause)
        {
            for (std::list<Node>::iterator CurrentNode = CardList.begin(); CurrentNode != CardList.end(); ++CurrentNode)
            {
                int CurPosX = static_cast<int>(CurrentNode->CardRander->GetTransform().GetPosition().X);
                int CurPosY = -30;
                CurrentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {175,175} });
            }
            IsPause = true;
        }
    }
    else
    {
        if (IsPause)
        {
            for (std::list<Node>::iterator CurrentNode = CardList.begin(); CurrentNode != CardList.end(); ++CurrentNode)
            {
                int CurPosX = static_cast<int>(CurrentNode->CardRander->GetTransform().GetPosition().X);
                int CurPosY = 0;
                CurrentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {175,175} });
            }
            IsPause = false;
        }
    }
}
