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

	void IsTileSet();
	void ShowAvailableTiles();

	UImageRenderer* Tile = nullptr;

	UImageRenderer* IsTile = nullptr;
	std::vector<std::vector<UImageRenderer*>> TileList;
	bool IsTileCheck = false;

	void DrawTileMap();
	void DrawTile(int xPos, int yPos, int tileWidth, int tileHeight);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	void BackStage();
	void MainStage();
	void BaseCamp();

};

