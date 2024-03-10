#pragma once
#include <EngineCore/Level.h>
#include "IntroRender.h"
#include "Enum.h"

class UIntroLevel : public ULevel
{
public:
	// constrcuter destructer
	UIntroLevel();
	~UIntroLevel();

	// delete Function
	UIntroLevel(const UIntroLevel& _Other) = delete;
	UIntroLevel(UIntroLevel&& _Other) noexcept = delete;
	UIntroLevel& operator=(const UIntroLevel& _Other) = delete;
	UIntroLevel& operator=(UIntroLevel&& _Other) noexcept = delete;

	void Idle();
	void Next();
	void Prev();
	void Skip();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	AIntroRender* Intro = nullptr;

	IntroState CurState = IntroState::Idle;
	void ChangeState(IntroState _State);
	void StateUpdate(float _DeltaTime);

};

