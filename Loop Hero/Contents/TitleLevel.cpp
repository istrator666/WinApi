#include "TitleLevel.h"
#include "TitleLogo.h"

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		ATitlelogo* Logo = SpawnActor<ATitlelogo>();
	}

}

void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}
