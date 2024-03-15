#pragma once
#include <EngineCore/Actor.h>


typedef int Card;
class Node
{
public:
	FVector StartPosition;
	FVector EndPosition;
	float Movetime = 0.0f;
	int CardTileNumber = 0;

	UImageRenderer* CardRander = nullptr;
	UCollision* CardCollision = nullptr;
};

class ATutorialRender;
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

	bool TutorialCardSetUp(bool _Check);
	bool TutorialCardComplete();

	void SetTutorialRender(ATutorialRender* _Map)
	{
		Map = _Map;
	}
	ATutorialRender* GetTutorialRender()
	{
		return Map;
	}
	
	int TutorialCardNumber = 0;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool IsPause = false;
	bool IsTutorialCardSetUp = false;
	float CardDeleteTime = 0.0f;

	void GamePause();

	std::list<Node> CardList;
	std::list<Node> DeleteList;
	Node* SelectNode = nullptr;

	ATutorialRender* Map = nullptr;

};

