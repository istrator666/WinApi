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
	EQInventoryIcon->SetImage("Weapons.png");
	EQInventoryIcon->CreateAnimation("Weapons", "Weapons.png", 0, 0, 0.3f, false);
	EQInventoryIcon->ChangeAnimation("Weapons");
	EQInventoryIcon->SetOrder(6);
	EQInventoryIcon->SetTransform({ {-42, -80}, {200,200} });
	//EQInventoryIcon->SetTransform({ {-42, -284}, {200,200} });

}
