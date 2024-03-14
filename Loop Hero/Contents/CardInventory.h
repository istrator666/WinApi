#pragma once
#include <EngineCore/Actor.h>

typedef int Card;
class Node
{
public:
	FVector StartPosition;
	FVector EndPosition;
	float Movetime = 0.0f;

	UImageRenderer* CardRander = nullptr;
	UCollision* CardCollision = nullptr;
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

	void AddCard(int _Card, FVector _MonsterPosition);
	void TutorialAddCard(int _Card, FVector _MonsterPosition);
	int CardListSize();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool IsPause = false;
	float CardDeleteTime = 0.0f;

	void GamePause();
	
	bool IsMouseDown = false;

	std::list<Node> CardList;
	std::list<Node> DeleteList;
	Node* SelectNode = nullptr;
};

