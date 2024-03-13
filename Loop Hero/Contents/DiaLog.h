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

	void DialogAnimation(float _DeltaTime);
	void StartNextText(int _DialogCount);
	void Text01();
	void Text02();
	void Text03();
	void Text04();
	void Text05();
	void Text06();
	void Text07();

	int DialogCount = 0;
	int TextCount = 0;
	UImageRenderer* DialogText = nullptr;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* DialogCharacter = nullptr;
	UImageRenderer* DialogBox = nullptr;
	UImageRenderer* DiaProgressbar = nullptr;
	UImageRenderer* DialogBackground = nullptr;

	float DiaLogMove = 0.0f;
	float DiaProgressbarTime = 1.0f;

};

