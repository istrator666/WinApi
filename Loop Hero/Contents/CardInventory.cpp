#include "CardInventory.h"
#include "MouseFunction.h"
#include <thread>

ACardInventory::ACardInventory()
{
}

ACardInventory::~ACardInventory()
{
}

void ACardInventory::AddCard(int _Card)
{
    for (size_t i = 0; i < _Card; i++)
    {
        Node CardNode;
        CardNode.CardRander = CreateImageRenderer();
        CardNode.CardRander->SetImage("Cards.png");
        CardNode.CardRander->SetOrder(7);
        CardNode.CardRander->CreateAnimation("Card", "Cards.png", 3, 3, 0.3f, false);
        CardNode.CardRander->ChangeAnimation("Card");
        CardList.push_back(CardNode);
    }

    if (CardList.size() > 13)
    {
        size_t StartSize = CardList.size();
        for (size_t i = 0; i < StartSize - 13; i++)
        {
            Node& Node = CardList.front();
            Node.CardRander->Destroy();
            CardList.erase(CardList.begin());

        }
    }

    int Count = 0;
    for (Node& CurNode : CardList)
    {
        CurNode.CardRander->SetTransform({ {75 * Count, 0}, {250,250} });
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
	GamePause();
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
                int CurPosY = -30; //static_cast<int>(CurrentNode->CardRander->GetTransform().GetPosition().Y) - 30;
                CurrentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {250,250} });
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
                int CurPosY = 0; //static_cast<int>(CurrentNode->CardRander->GetTransform().GetPosition().Y) + 30;
                CurrentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {250,250} });
            }
            IsPause = false;
        }
    }
}
