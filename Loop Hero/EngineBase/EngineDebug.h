#pragma once
#include <Windows.h>
#include <assert.h>
#include <string>
#include <string_view>

/// <summary>
/// LeakCheck -> �������� ���� �����Ҵ� �޸� üũ, MagBoxAssert->Ư�� ������ �������� ������ ���� �޽��� ��� �� ���α׷� �ߴ�
/// MessageBox�� C ��Ÿ�� ���ڿ��� ���ڷ� �޴µ�, std::string�� C++ ���ڿ� Ŭ�����̱� ������ C ��Ÿ�� ���ڷ� ��ȯ�� �ʿ��ϰ� c_str()�� ����ؼ� char* C ��Ÿ�� ���ڿ��� ��ȯ�Ѵ�.
/// char�� �ƴ� char*���� �޴� ������ ���ڿ��̱� ����.
/// </summary>
namespace EngineDebug
{
	#define LeakCheck _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	#define MsgBoxAssert(Value) \
	std::string ErrorText = std::string(Value); \
	MessageBoxA(nullptr, ErrorText.c_str(), "ġ���� ����", MB_OK); assert(false);

	void OutPutDebugText(std::string_view _DebugText);
}