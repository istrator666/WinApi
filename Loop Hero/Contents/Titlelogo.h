#pragma once
#include <EngineCore/Actor.h>


class ATitlelogo : public AActor
{
public:
	// constrcuter destructer
	ATitlelogo();
	~ATitlelogo();

	// delete Function
	ATitlelogo(const ATitlelogo& _Other) = delete;
	ATitlelogo(ATitlelogo&& _Other) noexcept = delete;
	ATitlelogo& operator=(const ATitlelogo& _Other) = delete;
	ATitlelogo& operator=(ATitlelogo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void IntroLogo();
	void BackGroundImage();
	void TitleMenu();

	float LogoChageTime = 2.0f;
	float TitleMoveTime = 8.0f;
	UImageRenderer* IntroLogoRenderer = nullptr;
	UImageRenderer* TitleLogoRenderer = nullptr;
};

