#pragma once
#include <EngineCore/Actor.h>

class AStageMap : public AActor
{
public:
	// constrcuter destructer
	AStageMap();
	~AStageMap();

	// delete Function
	AStageMap(const AStageMap& _Other) = delete;
	AStageMap(AStageMap&& _Other) noexcept = delete;
	AStageMap& operator=(const AStageMap& _Other) = delete;
	AStageMap& operator=(AStageMap&& _Other) noexcept = delete;

	void GameIntro();
	void SetMapImage(std::string_view _BackImageName, std::string_view _StageImageName, std::string_view _CampImageName);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* GameStartIntro = nullptr;
	UImageRenderer* BackStageRender = nullptr;
	UImageRenderer* MainStageRender = nullptr;
	UImageRenderer* BaseCampRender = nullptr;

	bool GameIntroCheck = false;
	int ImageNumber = 0;

};

