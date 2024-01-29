#pragma once
#include "EnginePath.h"
#include <list>

class EngineFile;
// Ό³Έν :
class EngineDirectory : public EnginePath
{
public:
	// constrcuter destructer
	EngineDirectory();
	~EngineDirectory();

	// delete Function
	EngineDirectory(const EngineDirectory& _Other) = delete;
	EngineDirectory(EngineDirectory&& _Other) noexcept = delete;
	EngineDirectory& operator=(const EngineDirectory& _Other) = delete;
	EngineDirectory& operator=(EngineDirectory&& _Other) noexcept = delete;

	std::list<EngineFile> AllFile();

protected:

private:

};

