#pragma once
#include <EngineCore\EngineCore.h>

class EmbodimentofScarletDevilContentsCore : public EngineCore
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
	void Start() override;
	void Update() override;
	void End() override;

private:

};

