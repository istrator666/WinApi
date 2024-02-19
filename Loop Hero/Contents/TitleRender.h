#pragma once
#include <EngineCore/Actor.h>


class ATitleRender : public AActor
{
public:
	// constrcuter destructer
	ATitleRender();
	~ATitleRender();

	// delete Function
	ATitleRender(const ATitleRender& _Other) = delete;
	ATitleRender(ATitleRender&& _Other) noexcept = delete;
	ATitleRender& operator=(const ATitleRender& _Other) = delete;
	ATitleRender& operator=(ATitleRender&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* IntroBackGroundRender = nullptr;
	UImageRenderer* IntroLogoRender = nullptr;
	UImageRenderer* BackGroundImageRender = nullptr;
	UImageRenderer* MenuRender = nullptr;
	UImageRenderer* TitleLogoRender = nullptr;
	UImageRenderer* PlayButton = nullptr;

	void IntroLogo();
	void BackGroundImage();
	void TitleMenu();

	float LogoChageTime = 4.0f;
	float TitleMoveTime = 9.0f;
};

