#include "StageMap.h"

#include <EnginePlatform/EngineInput.h>

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
	IsTileSet();
	MainStage();
	BaseCamp();
}

void AStageMap::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown('O'))
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 21; j++)
			{
				UImageRenderer* IsTile = IsTileList[i][j];
				IsTile->ActiveOff();
			}
		}
	}

}

void AStageMap::BackStage()
{
	UImageRenderer* BackStageRender = CreateImageRenderer();
	BackStageRender->SetImage("StageBackGround.png");
	BackStageRender->SetOrder(0);
	UWindowImage* BackStageImage = BackStageRender->GetImage();
	FVector BackStageImageScale = BackStageImage->GetScale();
	BackStageRender->SetTransform({ BackStageImageScale.Half2D(), BackStageImageScale });
}

void AStageMap::IsTileSet()
{
	IsTileList.resize(12, std::vector<UImageRenderer*>(21));
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			UImageRenderer* IsTile = CreateImageRenderer();
			IsTile->SetImage("IsTile.png");
			IsTile->SetOrder(1);
			IsTileList[i][j] = IsTile;
		}
	}

	int y = 75;

	for (int i = 0; i < 12; i++)
	{
		int x = 25;

		for (int j = 0; j < 21; j++)
		{
			IsTileList[i][j]->SetTransform({ {x, y}, {50, 50} });
			x += 50;
		}

		y += 50;
	}

	{
		IsTileList[4][10]->SetImage("DisableTile.png");
		IsTileList[4][11]->SetImage("DisableTile.png");
		IsTileList[5][9]->SetImage("DisableTile.png");
		IsTileList[5][11]->SetImage("DisableTile.png");
		IsTileList[6][9]->SetImage("DisableTile.png");
		IsTileList[6][10]->SetImage("DisableTile.png");

		IsTileList[2][9]->SetImage("DisableTile.png");
		IsTileList[2][10]->SetImage("DisableTile.png");
		IsTileList[2][11]->SetImage("DisableTile.png");
		IsTileList[2][12]->SetImage("DisableTile.png");

		IsTileList[3][8]->SetImage("DisableTile.png");
		IsTileList[3][13]->SetImage("DisableTile.png");

		IsTileList[4][7]->SetImage("DisableTile.png");
		IsTileList[4][13]->SetImage("DisableTile.png");

		IsTileList[5][7]->SetImage("DisableTile.png");
		IsTileList[5][13]->SetImage("DisableTile.png");

		IsTileList[6][7]->SetImage("DisableTile.png");
		IsTileList[6][13]->SetImage("DisableTile.png");

		IsTileList[7][7]->SetImage("DisableTile.png");
		IsTileList[7][12]->SetImage("DisableTile.png");

		IsTileList[8][8]->SetImage("DisableTile.png");
		IsTileList[8][9]->SetImage("DisableTile.png");
		IsTileList[8][10]->SetImage("DisableTile.png");
		IsTileList[8][11]->SetImage("DisableTile.png");
	}
}

void AStageMap::MainStage()
{
	UImageRenderer* MainStageRender = CreateImageRenderer();
	MainStageRender->SetImage("TutorialStage01.png");
	MainStageRender->SetOrder(2);
	UWindowImage* MainStageImage = MainStageRender->GetImage();
	FVector MainStageImageScale = MainStageImage->GetScale();
	MainStageRender->SetTransform({ {525, 325}, MainStageImageScale });
}

void AStageMap::BaseCamp()
{
	UImageRenderer* BaseCampRender = CreateImageRenderer();
	BaseCampRender->SetImage("BaseCamp01.png");
	BaseCampRender->SetOrder(3);
	UWindowImage* BaseCampImage = BaseCampRender->GetImage();
	FVector BaseCampImageScale = BaseCampImage->GetScale();
	BaseCampRender->SetTransform({ {575, 225}, BaseCampImageScale });
}



