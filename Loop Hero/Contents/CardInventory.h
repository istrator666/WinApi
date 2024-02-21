#pragma once
#include <EngineCore/Actor.h>

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

protected:

private:

};

