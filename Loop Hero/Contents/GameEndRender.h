#pragma once
#include <EngineCore/Actor.h>

class AGameEndRender : public AActor
{
public:
	// constrcuter destructer
	AGameEndRender();
	~AGameEndRender();

	// delete Function
	AGameEndRender(const AGameEndRender& _Other) = delete;
	AGameEndRender(AGameEndRender&& _Other) noexcept = delete;
	AGameEndRender& operator=(const AGameEndRender& _Other) = delete;
	AGameEndRender& operator=(AGameEndRender&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* GameEndImage = nullptr;

};

