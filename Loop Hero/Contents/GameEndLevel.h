#pragma once
#include <EngineCore/Level.h>
#include "GameEndRender.h"

class UGameEndLevel : public ULevel
{
public:
	// constrcuter destructer
	UGameEndLevel();
	~UGameEndLevel();

	// delete Function
	UGameEndLevel(const UGameEndLevel& _Other) = delete;
	UGameEndLevel(UGameEndLevel&& _Other) noexcept = delete;
	UGameEndLevel& operator=(const UGameEndLevel& _Other) = delete;
	UGameEndLevel& operator=(UGameEndLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	AGameEndRender* EndImage = nullptr;

};

