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

	UImageRenderer* BackGroundImageRenderer = nullptr;
	UImageRenderer* TitleLogoRenderer = nullptr;
	UImageRenderer* IntroLogoRenderer = nullptr;
	UImageRenderer* MenuRenderer = nullptr;

	float ChangeTime = 2.0f;
	float NextBGTime = 4.0f;
	float NextLogoTime = 6.0f;
	float NextMenuTime = 8.0f;
};

