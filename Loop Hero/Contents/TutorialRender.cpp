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
	TutorialText->SetText("모험 (지도위를 여행) 모드와 계획 (멈춤) 모드 사이를 전환하려면 스위치를 누르거나, 우클릭이나 스페이스바를 누르십시오. \n- 게임 모드를 바꿔 여정을 이어가십시오.");
}

void ATutorialRender::TutorialGuideArrow02()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("화면 위쪽의 하루 진행도를 눈여겨 보십시오. 하루가 끝나면 새로운 적이 나타날 수 있습니다. \n\n- 게임 모드를 전환해 여정을 이어가십시오.(스페이스 바, 마우스 우클릭, 모드변경)");
}

void ATutorialRender::TutorialGuideArrow03()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("여행, 전투, 그리고 대부분의 다른 행동은 자동으로 이루어집니다. 플레이어는 직접적으로 영향을 끼치지 않습니다. \n- 아무곳이나 눌러 계속 이어가십시오.");
}

void ATutorialRender::TutorialGuideArrow04()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("당신에겐 소지품과 아이템 슬롯이 있습니다. 어떻게 해야 할 지는 알 것입니다. \n- 물품을 장비한 후 계속 이어가십시오.");
}

void ATutorialRender::TutorialGuideArrow05()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("적을 쓰러트리고 나온 카드를 사용해 지도에 다양한 사물을 배치할 수 있습니다. 계획 모드는 이 때 사용됩니다. \n- 카드를 적당한 장소에 둬서 땅을 기억 하십시오.");
}

void ATutorialRender::TutorialGuideArrow06()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("잘 했습니다. \n- 이제 여정을 이어가십시오.");
}

void ATutorialRender::TutorialGuideArrow07()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("이미 알아차리셨듯, 전투 중에 새로운 물품이나 카드를 얻을 수 있습니다. \n어떤 물품은 대부분의 카드처럼 특별한 능력을 가지고 있습니다. 물품이나 카드에 마우스를 올려놓으면 그 정보를 알 수 \n있습니다. \n\n- 새로운 무기를 장비한 후 새 카드를 지도 위에 배치하여 계속 이어 가십시오.");
}

void ATutorialRender::TutorialGuideArrow08()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("특정 행동을 하게 되면 당장은 아니지만 나중에 필요할 자원을 얻을 수 있습니다. 지금 당장 설명하진 않을 것 입니다. \n- 게임 모드를 바꿔 여정을 이어가십시오. (스페이 바, 마우스 우클릭, 모드 변경");
}

void ATutorialRender::TutorialGuideArrow09()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("이 게임은 길을 따라 여정을 반복하는 게임입니다. 언제 영웅이 야영지로 돌아갈지는 당신이 결정해야 합니다... \n물론 적들의 이빨과 발톱이 결정을 내려줄 수도 있지만요. \n거의 언제든 후퇴할 수 있지만, 특별한 애니메이션이 나오면 안전하게 후퇴할 수 있습니다. \n\n- 버튼을 눌러 야영지로 퇴각하십시오.");
}


void ATutorialRender::TutorialGuideArrowEnd()
{
	UPArrow->SetActive(false);
	TutorialText->SetActive(false);
	RightArrow->SetActive(false);
	RightArrow2->SetActive(false);
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

	RightArrow2 = CreateImageRenderer();
	RightArrow2->SetImage("Right.png");
	RightArrow2->SetOrder(15);
	RightArrow2->SetTransform({ {1000, 50}, {250,250} });
	RightArrow2->CreateAnimation("Idle", "Right.png", 0, 36, 0.25f, true);
	RightArrow2->ChangeAnimation("Idle");
	RightArrow2->SetActive(false);

	TutorialText = CreateImageRenderer();
	TutorialText->SetTextColor(Color8Bit::White);
	TutorialText->SetTextSize(17);
	TutorialText->SetTextSortOption(Gdiplus::StringAlignmentNear, Gdiplus::StringAlignmentNear);
	TutorialText->SetOrder(15);
	TutorialText->SetTransform({ {25, 500}, {200,200} });
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