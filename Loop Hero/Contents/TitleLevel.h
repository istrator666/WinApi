#pragma once
#include <EngineCore/Level.h>
#include "TitleRender.h"
#include <EnginePlatform/EngineSound.h>


// ���� :
class UTitleLevel : public ULevel
{
public:
	// constrcuter destructer
	UTitleLevel();
	~UTitleLevel();

	// delete Function
	UTitleLevel(const UTitleLevel& _Other) = delete;
	UTitleLevel(UTitleLevel&& _Other) noexcept = delete;
	UTitleLevel& operator=(const UTitleLevel& _Other) = delete;
	UTitleLevel& operator=(UTitleLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	ATitleRender* Title = nullptr;
	UEngineSoundPlayer BackgroundBGM;

};

