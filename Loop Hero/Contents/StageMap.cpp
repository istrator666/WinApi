#include "StageMap.h"

AStageMap::AStageMap()
{
}

AStageMap::~AStageMap()
{
}

void AStageMap::BeginPlay()
{
	AActor::BeginPlay();
	
	BackStageRender = CreateImageRenderer();
	MainStageRender = CreateImageRenderer();
	BaseCampRender = CreateImageRenderer();
}

void AStageMap::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}


void AStageMap::SetMapImage(std::string_view _BackImageName, std::string_view _StageImageName, std::string_view _CampImageName)
{

	BackStageRender->SetImage(_BackImageName);
	UWindowImage* BackStageImage = BackStageRender->GetImage();
	FVector BackStageImageScale = BackStageImage->GetScale();
	BackStageRender->SetTransform({ BackStageImageScale.Half2D(), BackStageImageScale });

	MainStageRender->SetImage(_StageImageName);
	UWindowImage* MainStageImage = MainStageRender->GetImage();
	FVector MainStageImageScale = MainStageImage->GetScale();
	MainStageRender->SetTransform({ BackStageImageScale.Half2D(), MainStageImageScale });

	BaseCampRender->SetImage(_CampImageName);
	UWindowImage* BaseCampImage = BaseCampRender->GetImage();
	FVector BaseCampImageScale = BaseCampImage->GetScale();
	BaseCampRender->SetTransform({ {690, 260}, BaseCampImageScale });

}

