#pragma once
#include "EngineCore/Actor.h"

class AMouse : public AActor
{
public:
	// constrcuter destructer
	AMouse();
	~AMouse();



	// delete Function
	AMouse(const AMouse& _Other) = delete;
	AMouse(AMouse&& _Other) noexcept = delete;
	AMouse& operator=(const AMouse& _Other) = delete;
	AMouse& operator=(AMouse&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* MouseCollision = nullptr;

};

