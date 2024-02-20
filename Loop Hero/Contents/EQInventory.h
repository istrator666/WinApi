#pragma once
#include <EngineCore/Actor.h>

class AEQInventory : public AActor
{
public:
	// constrcuter destructer
	AEQInventory();
	~AEQInventory();

	// delete Function
	AEQInventory(const AEQInventory& _Other) = delete;
	AEQInventory(AEQInventory&& _Other) noexcept = delete;
	AEQInventory& operator=(const AEQInventory& _Other) = delete;
	AEQInventory& operator=(AEQInventory&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void EQInventory();
	UImageRenderer* EQInventoryRender = nullptr;

};

