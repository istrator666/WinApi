#include "EmbodimentofScarletDevilContentsCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayLevel.h"

EmbodimentofScarletDevilContentsCore::EmbodimentofScarletDevilContentsCore()
	: EngineCore()
{
}

EmbodimentofScarletDevilContentsCore::~EmbodimentofScarletDevilContentsCore()
{
}

void EmbodimentofScarletDevilContentsCore::BeginPlay()
{
	SetFrame(60);

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void EmbodimentofScarletDevilContentsCore::Tick(float _DeltaTime)
{
}

void EmbodimentofScarletDevilContentsCore::End()
{
}