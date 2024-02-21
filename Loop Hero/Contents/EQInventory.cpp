#include "EQInventory.h"

AEQInventory::AEQInventory()
{
}

AEQInventory::~AEQInventory()
{
}

void AEQInventory::BeginPlay()
{
	AActor::BeginPlay();
	EQInventory();
}

void AEQInventory::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}

void AEQInventory::EQInventory()
{
	EQInventoryRender = CreateImageRenderer();
	EQInventoryRender->SetImage("Equipment.png");
	EQInventoryRender->SetOrder(5);
	EQInventoryRender->SetTransform({ {1130, 360}, {295,730} });
}
