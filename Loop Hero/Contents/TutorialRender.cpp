#include "TutorialRender.h"
#include <EngineBase/EngineMath.cpp>
#include "Struct.h"

ATutorialRender::ATutorialRender()
{
}

ATutorialRender::~ATutorialRender()
{
}

void ATutorialRender::TutorialGuideArrow01()
{
	UPArrow->SetActive(true);
	TutorialText->SetActive(true);
	TutorialText->SetText("모험 (지도위를 여행) 모드와 계획 (멈춤) 모드 사이를 전환하려면 스위치를 누르거나, 우클릭이나 스페이스바를 누르십시오. \n - 게임 모드를 바꿔 여정을 이어가십시오.");
}

void ATutorialRender::TutorialGuideArrow02()
{

}

void ATutorialRender::TutorialGuideArrow03()
{

}

void ATutorialRender::TutorialGuideArrow04()
{

}

void ATutorialRender::TutorialGuideArrow05()
{

}


void ATutorialRender::TutorialGuideArrowEnd()
{
	UPArrow->SetActive(false);
	TutorialText->SetActive(false);
	//RightArrow->SetActive(false);
}

void ATutorialRender::BeginPlay()
{
	AActor::BeginPlay();
	BackStage();

	DrawTileMap();

	MainStage();
	//BaseCamp();

	UPArrow = CreateImageRenderer();
	UPArrow->SetImage("Up.png");
	UPArrow->SetOrder(15);
	UPArrow->SetTransform({ {500, 50}, {250,250} });
	UPArrow->CreateAnimation("Idle", "Up.png", 0, 36, 0.25f, true);
	UPArrow->ChangeAnimation("Idle");
	UPArrow->SetActive(false);

	RightArrow = CreateImageRenderer();
	RightArrow->SetImage("Right.png");
	RightArrow->SetOrder(15);
	RightArrow->SetTransform({ {1000, 250}, {250,250} });
	RightArrow->CreateAnimation("Idle", "Right.png", 0, 36, 0.25f, true);
	RightArrow->ChangeAnimation("Idle");
	RightArrow->SetActive(false);

	TutorialText = CreateImageRenderer();
	TutorialText->SetTextColor(Color8Bit::White);
	TutorialText->SetTextSize(18);
	TutorialText->SetOrder(15);
	TutorialText->SetTransform({ {500, 500}, {200,200} });
	TutorialText->SetActive(false);
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
	Tile->SetImage("IsTile.png");
	Tile->SetOrder(1);
	Tile->SetActive(false);
	Tile->SetTransform({ {xPos, yPos}, {tileWidth, tileHeight} });

	LastCreatedTile = Tile;
}