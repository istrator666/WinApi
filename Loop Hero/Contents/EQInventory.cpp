#include "EQInventory.h"

EQInventory::EQInventory()
{
}

EQInventory::~EQInventory()
{
}

void EQInventory::AEQInventoryUI::BeginPlay()
{
	AActor::BeginPlay();
	EQInventoryUI();
}

void EQInventory::AEQInventoryUI::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void EQInventory::AEQInventoryUI::EQInventoryUI()
{
	EQInventoryRender = CreateImageRenderer();
	EQInventoryRender->SetImage("Equipment.png");
	EQInventoryRender->SetOrder(5);
	EQInventoryRender->SetTransform({ {0, 0}, {295,730} });


	EQInventoryIcon = CreateImageRenderer();
	EQInventoryIcon->SetImage("Equipment.png");
	EQInventoryIcon->SetOrder(5);
	EQInventoryIcon->SetTransform({ {0, 0}, {295,730} });
}
