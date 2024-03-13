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
	TutorialText->SetText("���� (�������� ����) ���� ��ȹ (����) ��� ���̸� ��ȯ�Ϸ��� ����ġ�� �����ų�, ��Ŭ���̳� �����̽��ٸ� �����ʽÿ�. \n- ���� ��带 �ٲ� ������ �̾�ʽÿ�.");
}

void ATutorialRender::TutorialGuideArrow02()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("ȭ�� ������ �Ϸ� ���൵�� ������ ���ʽÿ�. �Ϸ簡 ������ ���ο� ���� ��Ÿ�� �� �ֽ��ϴ�. \n\n- ���� ��带 ��ȯ�� ������ �̾�ʽÿ�.(�����̽� ��, ���콺 ��Ŭ��, ��庯��)");
}

void ATutorialRender::TutorialGuideArrow03()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("����, ����, �׸��� ��κ��� �ٸ� �ൿ�� �ڵ����� �̷�����ϴ�. �÷��̾�� ���������� ������ ��ġ�� �ʽ��ϴ�. \n- �ƹ����̳� ���� ��� �̾�ʽÿ�.");
}

void ATutorialRender::TutorialGuideArrow04()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("��ſ��� ����ǰ�� ������ ������ �ֽ��ϴ�. ��� �ؾ� �� ���� �� ���Դϴ�. \n- ��ǰ�� ����� �� ��� �̾�ʽÿ�.");
}

void ATutorialRender::TutorialGuideArrow05()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("���� ����Ʈ���� ���� ī�带 ����� ������ �پ��� �繰�� ��ġ�� �� �ֽ��ϴ�. ��ȹ ���� �� �� ���˴ϴ�. \n- ī�带 ������ ��ҿ� �ּ� ���� ��� �Ͻʽÿ�.");
}

void ATutorialRender::TutorialGuideArrow06()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("�� �߽��ϴ�. \n- ���� ������ �̾�ʽÿ�.");
}

void ATutorialRender::TutorialGuideArrow07()
{
	TutorialText->SetActive(true);
	RightArrow->SetActive(true);
	RightArrow2->SetActive(true);
	TutorialText->SetText("�̹� �˾������̵�, ���� �߿� ���ο� ��ǰ�̳� ī�带 ���� �� �ֽ��ϴ�. \n� ��ǰ�� ��κ��� ī��ó�� Ư���� �ɷ��� ������ �ֽ��ϴ�. ��ǰ�̳� ī�忡 ���콺�� �÷������� �� ������ �� �� \n�ֽ��ϴ�. \n\n- ���ο� ���⸦ ����� �� �� ī�带 ���� ���� ��ġ�Ͽ� ��� �̾� ���ʽÿ�.");
}

void ATutorialRender::TutorialGuideArrow08()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("Ư�� �ൿ�� �ϰ� �Ǹ� ������ �ƴ����� ���߿� �ʿ��� �ڿ��� ���� �� �ֽ��ϴ�. ���� ���� �������� ���� �� �Դϴ�. \n- ���� ��带 �ٲ� ������ �̾�ʽÿ�. (������ ��, ���콺 ��Ŭ��, ��� ����");
}

void ATutorialRender::TutorialGuideArrow09()
{
	TutorialText->SetActive(true);
	TutorialText->SetText("�� ������ ���� ���� ������ �ݺ��ϴ� �����Դϴ�. ���� ������ �߿����� ���ư����� ����� �����ؾ� �մϴ�... \n���� ������ �̻��� ������ ������ ������ ���� ��������. \n���� ������ ������ �� ������, Ư���� �ִϸ��̼��� ������ �����ϰ� ������ �� �ֽ��ϴ�. \n\n- ��ư�� ���� �߿����� ���Ͻʽÿ�.");
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