#pragma once
#include <EngineCore/Actor.h>

typedef int Card;
class Node
{
public:
	UImageRenderer* CardRander = nullptr;
	Node* Next = nullptr;
	Node* Prev = nullptr;
};

class ACardInventory : public AActor
{
public:
	// constrcuter destructer
	ACardInventory();
	~ACardInventory();

	// delete Function
	ACardInventory(const ACardInventory& _Other) = delete;
	ACardInventory(ACardInventory&& _Other) noexcept = delete;
	ACardInventory& operator=(const ACardInventory& _Other) = delete;
	ACardInventory& operator=(ACardInventory&& _Other) noexcept = delete;

	void AddCard(int card);
	int CardListSize();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	bool IsPause = false;

	void GamePause();

	std::list<Node> CardList;

};

