#include "EngineFile.h"

UEngineFile::UEngineFile()
{
}

UEngineFile::UEngineFile(std::filesystem::path _Path)
	: UEnginePath(_Path) // �θ�Ŭ���� �����ڸ� ȣ���Ͽ� ��� �ʱ�ȭ
{

}

UEngineFile::~UEngineFile()
{
}