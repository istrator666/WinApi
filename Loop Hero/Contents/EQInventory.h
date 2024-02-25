#pragma once
#include <EngineCore/Actor.h>

class EQInventory
{
public:
	// constrcuter destructer
	EQInventory();
	~EQInventory();

	// delete Function
	EQInventory(const EQInventory& _Other) = delete;
	EQInventory(EQInventory&& _Other) noexcept = delete;
	EQInventory& operator=(const EQInventory& _Other) = delete;
	EQInventory& operator=(EQInventory&& _Other) noexcept = delete;

	class AEQInventoryUI : public AActor
	{
	public:
		void EQInventoryUI();

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* EQInventoryRender = nullptr;
	};

protected:

private:

};

