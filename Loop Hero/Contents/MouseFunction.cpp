#include "MouseFunction.h"

UMouseFunction::UMouseFunction()
{

}

UMouseFunction::~UMouseFunction()
{

}

FVector UMouseFunction::GetMousePos()
{
	return GEngine->MainWindow.GetMousePosition();
}
