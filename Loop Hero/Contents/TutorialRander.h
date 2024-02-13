#pragma once
#include <EngineCore/Actor.h>


class ATutorialRander : public AActor
{
public:
	// constrcuter destructer
	ATutorialRander();
	~ATutorialRander();

	// delete Function
	ATutorialRander(const ATutorialRander& _Other) = delete;
	ATutorialRander(ATutorialRander&& _Other) noexcept = delete;
	ATutorialRander& operator=(const ATutorialRander& _Other) = delete;
	ATutorialRander& operator=(ATutorialRander&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void TutorialStage();
	void TutorialBaseCamp();
	void PlayerRender();

};

