#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>

class UMouseFunction
{
public:
	// delete Function
	UMouseFunction(const UMouseFunction& _Other) = delete;
	UMouseFunction(UMouseFunction&& _Other) noexcept = delete;
	UMouseFunction& operator=(const UMouseFunction& _Other) = delete;
	UMouseFunction& operator=(UMouseFunction&& _Other) noexcept = delete;

	static FVector GetMousePos();

protected:

private:
	// constrcuter destructer
	UMouseFunction();
	~UMouseFunction();

};

