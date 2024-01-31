#pragma once
#include <EngineCore\EngineCore.h>

class EmbodimentofScarletDevilContentsCore : public UEngineCore
{
public:
	// constrcuter destructer
	EmbodimentofScarletDevilContentsCore();
	~EmbodimentofScarletDevilContentsCore();

	// delete Function
	EmbodimentofScarletDevilContentsCore(const EmbodimentofScarletDevilContentsCore& _Other) = delete;
	EmbodimentofScarletDevilContentsCore(EmbodimentofScarletDevilContentsCore&& _Other) noexcept = delete;
	EmbodimentofScarletDevilContentsCore& operator=(const EmbodimentofScarletDevilContentsCore& _Other) = delete;
	EmbodimentofScarletDevilContentsCore& operator=(EmbodimentofScarletDevilContentsCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void End() override;

private:

};

