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

		// EQ List
		void SetupEQ();
		void DrawEQ(int xPos, int yPos, int tileWidth, int tileHeight);
		UImageRenderer* EQIcon = nullptr;
		UImageRenderer* LastCreatedTile = nullptr;
		std::vector<std::vector<UImageRenderer*>> EQList;

		//Inventory List
		void SetupInventory();
		void DrawInventory(int xPos, int yPos, int tileWidth, int tileHeight);
		UImageRenderer* EQInventoryIcon = nullptr;
		UImageRenderer* LastCreatedTile = nullptr;
		std::vector<std::vector<UImageRenderer*>> InventoryList;
		

	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* EQInventoryRender = nullptr;
		
	};

protected:

private:


};

