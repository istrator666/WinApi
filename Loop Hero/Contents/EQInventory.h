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

		void TutorialAddEQ(FVector _MonsterPosition);
		
	protected:
		void BeginPlay() override;
		void Tick(float _DeltaTime) override;

	private:
		UImageRenderer* EQInventoryRender = nullptr;

		UImageRenderer* EQIcon = nullptr;
		UCollision* EQIconCollision = nullptr;

		UImageRenderer* EQInventoryIcon = nullptr;
		UCollision* EQInventoryIconCollision = nullptr;
		FVector StartPosition;
		FVector EndPosition;

		UImageRenderer* SelectEQInventoryIcon = nullptr;
		UCollision* SelectEQInventoryIconCollision = nullptr;

		float Movetime = 0.0f;
		
	};

protected:

private:


};

