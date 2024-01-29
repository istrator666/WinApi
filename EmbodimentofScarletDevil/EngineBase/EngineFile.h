#pragma once
#include "EnginePath.h"

// Ό³Έν :
class EngineFile : public EnginePath
{
public:
	// constrcuter destructer
	EngineFile();
	~EngineFile();

	// delete Function
	EngineFile(const EngineFile& _Other) = delete;
	EngineFile(EngineFile&& _Other) noexcept = delete;
	EngineFile& operator=(const EngineFile& _Other) = delete;
	EngineFile& operator=(EngineFile&& _Other) noexcept = delete;

protected:

private:

};

