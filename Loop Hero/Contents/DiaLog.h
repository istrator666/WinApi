#pragma once
#include <EngineCore/Actor.h>

class ADiaLog : public AActor
{
public:
	// constrcuter destructer
	ADiaLog();
	~ADiaLog();

	// delete Function
	ADiaLog(const ADiaLog& _Other) = delete;
	ADiaLog(ADiaLog&& _Other) noexcept = delete;
	ADiaLog& operator=(const ADiaLog& _Other) = delete;
	ADiaLog& operator=(ADiaLog&& _Other) noexcept = delete;

	void DialogPlayer();
	void DialogBoxFuntion();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* DialogCharacter = nullptr;
	UImageRenderer* DialogBox = nullptr;
	UImageRenderer* DiaProgressbar = nullptr;

};

