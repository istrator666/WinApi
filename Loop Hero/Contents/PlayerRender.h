#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class APlayerRender : public AActor
{
public:
	// constrcuter destructer
	APlayerRender();
	~APlayerRender();

	// delete Function
	APlayerRender(const APlayerRender& _Other) = delete;
	APlayerRender(APlayerRender&& _Other) noexcept = delete;
	APlayerRender& operator=(const APlayerRender& _Other) = delete;
	APlayerRender& operator=(APlayerRender&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	void PlayerRenderer();

};

