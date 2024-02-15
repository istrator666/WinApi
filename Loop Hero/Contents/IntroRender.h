#pragma once
#include <EngineCore/Actor.h>

class AIntroRender : public AActor
{
public:
	// constrcuter destructer
	AIntroRender();
	~AIntroRender();

	// delete Function
	AIntroRender(const AIntroRender& _Other) = delete;
	AIntroRender(AIntroRender&& _Other) noexcept = delete;
	AIntroRender& operator=(const AIntroRender& _Other) = delete;
	AIntroRender& operator=(AIntroRender&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* GameStartIntro = nullptr;

	bool GameIntroCheck = false;
	int ImageNumber = 0;
	void GameIntro();
};

