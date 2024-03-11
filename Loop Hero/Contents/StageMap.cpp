#include "StageMap.h"

#include <EnginePlatform/EngineInput.h>
#include "TestStageLevel.h"

AStageMap::AStageMap()
{
}

AStageMap::~AStageMap()
{
}

void AStageMap::BeginPlay()
{
	AActor::BeginPlay();
	
	BackStage();
	MainStage();
	BaseCamp();

	DrawTileMap();
}

void AStageMap::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	ShowAvailableTiles();
}

void AStageMap::BackStage()
{
	UImageRenderer* BackStageRender = CreateImageRenderer();
	BackStageRender->SetImage("StageBackGround.png");
	BackStageRender->SetOrder(0);
	BackStageRender->SetTransform({ {615, 335}, {1280, 720} });
}

void AStageMap::DrawTileMap()
{

	for (int y = 0; y < TileInfo::Rows; ++y)
	{
		for (int x = 0; x < TileInfo::Cols; ++x)
		{

			int xPos = x * TileInfo::Size;
			int yPos = y * TileInfo::Size;

			DrawTile(xPos, yPos, TileInfo::Size, TileInfo::Size);
		}
	}
}

void AStageMap::DrawTile(int xPos, int yPos, int tileWidth, int tileHeight)
{
	Tile = CreateImageRenderer();
	Tile->SetImage("IsTile.png");
	Tile->SetOrder(1);
	Tile->SetActive(true);
	Tile->SetTransform({ {xPos, yPos}, {tileWidth, tileHeight} });
}

//void AStageMap::IsTileSet()
//{
//	TileList.resize(12, std::vector<UImageRenderer*>(21));
//	for (int i = 0; i < 12; i++)
//	{
//		for (int j = 0; j < 21; j++)
//		{
//			IsTile = CreateImageRenderer();
//			IsTile->SetImage("IsTile.png");
//			IsTile->SetOrder(1);
//			IsTile->SetActive(false);
//			TileList[i][j] = IsTile;
//		}
//	}
//
//	int y = 75;
//
//	for (int i = 0; i < 12; i++)
//	{
//		int x = 25;
//
//		for (int j = 0; j < 21; j++)
//		{
//			TileList[i][j]->SetTransform({ {x, y}, {50, 50} });
//			x += 50;
//		}
//
//		y += 50;
//	}
//
//	{
//		TileList[4][10]->SetImage("DisableTile.png");
//		TileList[4][11]->SetImage("DisableTile.png");
//		TileList[5][9]->SetImage("DisableTile.png");
//		TileList[5][11]->SetImage("DisableTile.png");
//		TileList[6][9]->SetImage("DisableTile.png");
//		TileList[6][10]->SetImage("DisableTile.png");
//
//		TileList[2][9]->SetImage("DisableTile.png");
//		TileList[2][10]->SetImage("DisableTile.png");
//		TileList[2][11]->SetImage("DisableTile.png");
//		TileList[2][12]->SetImage("DisableTile.png");
//
//		TileList[3][8]->SetImage("DisableTile.png");
//		TileList[3][13]->SetImage("DisableTile.png");
//
//		TileList[4][7]->SetImage("DisableTile.png");
//		TileList[4][13]->SetImage("DisableTile.png");
//
//		TileList[5][7]->SetImage("DisableTile.png");
//		TileList[5][13]->SetImage("DisableTile.png");
//
//		TileList[6][7]->SetImage("DisableTile.png");
//		TileList[6][13]->SetImage("DisableTile.png");
//
//		TileList[7][7]->SetImage("DisableTile.png");
//		TileList[7][12]->SetImage("DisableTile.png");
//
//		TileList[8][8]->SetImage("DisableTile.png");
//		TileList[8][9]->SetImage("DisableTile.png");
//		TileList[8][10]->SetImage("DisableTile.png");
//		TileList[8][11]->SetImage("DisableTile.png");
//	}
//}

void AStageMap::ShowAvailableTiles()
{
	if (UEngineInput::IsDown('O'))
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				Tile = TileList[i][j];
				Tile->SetActive(false);
			}
		}
	}
	else if (UEngineInput::IsDown('T'))
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				Tile = TileList[i][j];
				Tile->SetActive(true);
			}
		}
	}
}

void AStageMap::MainStage()
{
	UImageRenderer* MainStageRender = CreateImageRenderer();
	MainStageRender->SetImage("TutorialStage01.png");
	MainStageRender->SetOrder(2);
	UWindowImage* MainStageImage = MainStageRender->GetImage();
	FVector MainStageImageScale = MainStageImage->GetScale();
	MainStageRender->SetTransform({ {500, 300}, MainStageImageScale });
}

void AStageMap::BaseCamp()
{
	UImageRenderer* BaseCampRender = CreateImageRenderer();
	BaseCampRender->SetImage("BaseCamp01.png");
	BaseCampRender->SetOrder(3);
	UWindowImage* BaseCampImage = BaseCampRender->GetImage();
	FVector BaseCampImageScale = BaseCampImage->GetScale();
	BaseCampRender->SetTransform({ {550, 200}, BaseCampImageScale });
}



