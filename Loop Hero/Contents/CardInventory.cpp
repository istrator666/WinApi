#include "CardInventory.h"
#include "MouseFunction.h"
#include <thread>

ACardInventory::ACardInventory()
{
}

ACardInventory::~ACardInventory()
{
	while (head) 
	{
		Node* next = head->Next;
		delete head;
		head = next;
	}
}

void ACardInventory::ACardInventory::BeginPlay()
{
	AActor::BeginPlay();
	CardList();
}

void ACardInventory::ACardInventory::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	GamePause();
}

void ACardInventory::CardList()
{
	for (int i = 0; i < 13; ++i) {
		Node* newNode = new Node();
		newNode->CardRander = CreateImageRenderer();
		newNode->CardRander->SetImage("Cards.png");
		newNode->CardRander->SetOrder(7);
		newNode->CardRander->SetTransform({ {75 * i, 0}, {250,250} });
		newNode->CardRander->CreateAnimation("ZeroBubble", "Cards.png", 3, 3, 0.3f, false);
		newNode->CardRander->ChangeAnimation("ZeroBubble");
		//newNode->CardRander->SetActive(false);

		if (head == nullptr) {
			head = tail = newNode;
		}
		else {
			tail->Next = newNode;
			newNode->Prev = tail;
			tail = newNode;
		}
	}
}

void ACardInventory::GamePause()
{
    FVector PosCheck = UMouseFunction::GetMousePos();

    if ((0 <= PosCheck.X && 975 >= PosCheck.X) && (650 <= PosCheck.Y && 800 >= PosCheck.Y))
    {
        if (!IsPause)
        {
            Node* currentNode = head;
            double delay = 0.0;
            while (currentNode != nullptr)
            {
                int CurPosX = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().X);
                int CurPosY = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().Y) - 30;
                std::thread([currentNode, CurPosX, CurPosY, delay]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::round(delay * 1000))));
                    currentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {250,250} });
                    }).detach();

                    delay += 0.1;
                    currentNode = currentNode->Next;
            }
            IsPause = true;
        }
    }
    else
    {
        if (IsPause)
        {
            Node* currentNode = head;
            double delay = 0.0;
            while (currentNode != nullptr)
            {
                int CurPosX = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().X);
                int CurPosY = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().Y) + 30;
                std::thread([currentNode, CurPosX, CurPosY, delay]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::round(delay * 1000))));
                    currentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {250,250} });
                    }).detach();

                    delay += 0.1;
                    currentNode = currentNode->Next;
            }
            IsPause = false;
        }
    }
}

//void ACardInventory::GamePause()
//{
//	FVector PosCheck = UMouseFunction::GetMousePos();
//
//
//
//	if ((0 <= PosCheck.X && 975 >= PosCheck.X) && (650 <= PosCheck.Y && 800 >= PosCheck.Y))
//	{
//		if (!IsPause)
//		{
//			Node* currentNode = head;
//			while (currentNode != nullptr)
//			{
//				int CurPosX = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().X);
//				int CurPosY = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().Y) - 30;
//				currentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {250,250} });
//				currentNode = currentNode->Next;
//			}
//			IsPause = true;
//		}
//	}
//	else
//	{
//		if (IsPause)
//		{
//			Node* currentNode = head;
//			while (currentNode != nullptr)
//			{
//				int CurPosX = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().X);
//				int CurPosY = static_cast<int>(currentNode->CardRander->GetTransform().GetPosition().Y) + 30;
//				FVector CurPos = currentNode->CardRander->GetTransform().GetPosition();
//				currentNode->CardRander->SetTransform({ {CurPosX, CurPosY}, {250,250} });
//				currentNode = currentNode->Next;
//			}
//			IsPause = false;
//		}
//	}
//}
