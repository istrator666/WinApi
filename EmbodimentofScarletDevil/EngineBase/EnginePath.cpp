#include "EnginePath.h"
#include <Windows.h>

EnginePath::EnginePath()
	: Path(std::filesystem::current_path())
{

}

EnginePath::~EnginePath()
{
}

bool EnginePath::IsFile()
{
	return !std::filesystem::is_directory(Path);
}
bool EnginePath::IsDirectory()
{
	return std::filesystem::is_directory(Path);
}