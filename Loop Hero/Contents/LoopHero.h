#pragma once
#include <EngineCore/EngineCore.h>

class LoopHeroContentsCore : public UEngineCore
{
public:
	// constrcuter destructer
	LoopHeroContentsCore();
	~LoopHeroContentsCore();

	// delete Function
	LoopHeroContentsCore(const LoopHeroContentsCore& _Other) = delete;
	LoopHeroContentsCore(LoopHeroContentsCore&& _Other) noexcept = delete;
	LoopHeroContentsCore& operator=(const LoopHeroContentsCore& _Other) = delete;
	LoopHeroContentsCore& operator=(LoopHeroContentsCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

private:

};

