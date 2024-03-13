#pragma once
#include <EngineCore/Actor.h>


class ATutorialRender : public AActor
{
public:
	// constrcuter destructer
	ATutorialRender();
	~ATutorialRender();

	// delete Function
	ATutorialRender(const ATutorialRender& _Other) = delete;
	ATutorialRender(ATutorialRender&& _Other) noexcept = delete;
	ATutorialRender& operator=(const ATutorialRender& _Other) = delete;
	ATutorialRender& operator=(ATutorialRender&& _Other) noexcept = delete;

	// ¸Ê »ý¼º
	void DrawTileMap();
	void DrawTile(int xPos, int yPos, int tileWidth, int tileHeight);
	UImageRenderer* Tile = nullptr;
	UImageRenderer* LastCreatedTile = nullptr;
	std::vector<std::vector<UImageRenderer*>> TileList;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BackStageRender = nullptr;



	void BackStage();
	void MainStage();

};

