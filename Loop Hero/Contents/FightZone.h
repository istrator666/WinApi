#pragma once
#include <EngineCore/Actor.h>

class AFightZone : public AActor
{
public:
	// constrcuter destructer
	AFightZone();
	~AFightZone();

	// delete Function
	AFightZone(const AFightZone& _Other) = delete;
	AFightZone(AFightZone&& _Other) noexcept = delete;
	AFightZone& operator=(const AFightZone& _Other) = delete;
	AFightZone& operator=(AFightZone&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void FightZone();
	UImageRenderer* FightZoneRender = nullptr;

};

