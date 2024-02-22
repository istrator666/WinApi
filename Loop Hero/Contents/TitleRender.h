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
	UImageRenderer* IntroLogoRender2 = nullptr;
	UImageRenderer* BackGroundImageRender = nullptr;
	UImageRenderer* MenuRender = nullptr;
	UImageRenderer* TitleLogoRender = nullptr;
	UImageRenderer* PlayButtonRender = nullptr;

	void IntroLogo();
	void BackGroundImage();
	void TitleMenu();
	void MenuMove(float _DeltaTime);
	void AlphaUpdate(UImageRenderer* _RendererAlpha, float _DeltaTime);

	float BackTime = 7.0f;
	float LogoTime = 10.0f;
	float TitleMoveTime = 14.0f;
	float IntroAlpha = 0.0f;
	float BackAlpha = 0.0f;
	float LogoAlpha = 0.0f;
	float MenuDT = 0.0f;

	bool IsAlphaIncreasing = false;

};

