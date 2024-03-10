#pragma once
#include <EngineCore/Actor.h>
#include "MouseFunction.h"


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

	int ImageNumber = 0;
	UImageRenderer* GameStartIntro = nullptr;
	UImageRenderer* IntroBackButton = nullptr;
	UImageRenderer* IntroSkipButton = nullptr;
	UImageRenderer* IntroProgressIcon = nullptr;

	FVector PosCheck = UMouseFunction::GetMousePos();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void GameIntro();

};

