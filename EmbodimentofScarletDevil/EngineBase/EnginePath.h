#pragma once
#include <string>
#include <filesystem> 


// Ό³Έν : 
class EnginePath
{
public:
	// constrcuter destructer
	EnginePath();
	~EnginePath();

	// delete Function
	EnginePath(const EnginePath& _Other) = delete;
	EnginePath(EnginePath&& _Other) noexcept = delete;
	EnginePath& operator=(const EnginePath& _Other) = delete;
	EnginePath& operator=(EnginePath&& _Other) noexcept = delete;


	bool IsFile();
	bool IsDirectory();

protected:

private:

	std::filesystem::path Path;
};

