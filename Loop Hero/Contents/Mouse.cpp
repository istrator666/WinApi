#include "Mouse.h"
#include "EngineCore/EngineCore.h"
#include "Enum.h"

AMouse::AMouse()
{
}

AMouse::~AMouse()
{
}

void AMouse::BeginPlay()
{
	AActor::BeginPlay();
	MouseCollision = CreateCollision(ECollision::Mouse);
	MouseCollision->SetScale({50,50});
}

void AMouse::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	SetActorLocation(GEngine->MainWindow.GetMousePosition());

}