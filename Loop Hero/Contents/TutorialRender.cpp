#include "TutorialRender.h"
#include <EngineBase/EngineMath.cpp>
#include "Struct.h"

ATutorialRender::ATutorialRender()
{
}

ATutorialRender::~ATutorialRender()
{
}



void ATutorialRender::BeginPlay()
{
	AActor::BeginPlay();
	BackStage();

	DrawTileMap();

	MainStage();
	//BaseCamp();
}

void ATutorialRender::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ATutorialRender::BackStage()
{
	BackStageRender = CreateImageRenderer();
	BackStageRender->SetImage("StageBackGround.png");
	BackStageRender->SetOrder(0);
	BackStageRender->SetTransform({ {615, 335}, {1280, 720} });
}

void ATutorialRender::MainStage()
{
	TileList[4][11]->SetImage("BaseCamp01.png");
	TileList[4][11]->SetActive(true);

	TileList[4][12]->SetImage("tile04.png");
	TileList[4][12]->SetActive(true);

	TileList[5][12]->SetImage("tile01.png");
	TileList[5][12]->SetActive(true);

	TileList[6][12]->SetImage("tile01.png");
	TileList[6][12]->SetActive(true);

	TileList[7][12]->SetImage("tile05.png");
	TileList[7][12]->SetActive(true);

	TileList[7][11]->SetImage("tile02.png");
	TileList[7][11]->SetActive(true);

	TileList[8][11]->SetImage("tile05.png");
	TileList[8][11]->SetActive(true);

	TileList[8][10]->SetImage("tile03.png");
	TileList[8][10]->SetActive(true);

	TileList[8][9]->SetImage("tile03.png");
	TileList[8][9]->SetActive(true);

	TileList[8][8]->SetImage("tile06.png");
	TileList[8][8]->SetActive(true);

	TileList[7][8]->SetImage("tile01.png");
	TileList[7][8]->SetActive(true);

	TileList[6][8]->SetImage("tile01.png");
	TileList[6][8]->SetActive(true);

	TileList[5][8]->SetImage("tile02.png");
	TileList[5][8]->SetActive(true);

	TileList[5][9]->SetImage("tile05.png");
	TileList[5][9]->SetActive(true);

	TileList[4][9]->SetImage("tile02.png");
	TileList[4][9]->SetActive(true);

	TileList[4][10]->SetImage("tile03.png");
	TileList[4][10]->SetActive(true);

}

void ATutorialRender::DrawTileMap()
{
	TileList.resize(TileInfo::Rows, std::vector<UImageRenderer*>(TileInfo::Cols, nullptr));

	for (int y = 0; y < TileInfo::Rows; ++y)
	{
		for (int x = 0; x < TileInfo::Cols; ++x)
		{

			int xPos = x * TileInfo::Size;
			int yPos = y * TileInfo::Size;

			DrawTile(xPos, yPos, TileInfo::Size, TileInfo::Size);

			TileList[y][x] = LastCreatedTile;
		}
	}
}

void ATutorialRender::DrawTile(int xPos, int yPos, int tileWidth, int tileHeight)
{
	Tile = CreateImageRenderer();
	Tile->SetImage("Tiles", 10);
	Tile->SetOrder(1);
	Tile->SetActive(false);
	Tile->SetTransform({ {xPos, yPos}, {tileWidth, tileHeight} });

	LastCreatedTile = Tile;
}

void ATutorialRender::ToggleTilesActiveState(bool newState)
{
	for (int y = 0; y < TileInfo::Rows; ++y)
	{
		for (int x = 0; x < TileInfo::Cols; ++x)
		{
			if (TileList[y][x] != nullptr && TileList[y][x]->GetImageIndex() == 10)
			{
				TileList[y][x]->SetActive(newState);
			}
		}
	}
}