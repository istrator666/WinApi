#include "EngineFile.h"

UEngineFile::UEngineFile()
{
}

UEngineFile::UEngineFile(std::filesystem::path _Path)
	: UEnginePath(_Path) // 부모클래스 생성자를 호출하여 경로 초기화
{

}

UEngineFile::~UEngineFile()
{
}