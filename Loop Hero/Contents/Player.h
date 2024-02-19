#pragma once
#include <EngineCore/Actor.h>
#include <list>

// ���� :
class APlayer : public AActor
{
public:
	// constrcuter destructer
	APlayer();
	~APlayer();

	// delete Function
	APlayer(const APlayer& _Other) = delete;
	APlayer(APlayer&& _Other) noexcept = delete;
	APlayer& operator=(const APlayer& _Other) = delete;
	APlayer& operator=(APlayer&& _Other) noexcept = delete;

	void SetPlayerImage();
	void SetWayPoint(FVector _WayPoint);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void WayPoints(float _DeltaTime);

	UImageRenderer* PlayerRender = nullptr;

	std::list<FVector> WayPoint;
	std::list<FVector>::iterator CurrentWayPoint;
	float MoveSpeed = 100.0f;

};

