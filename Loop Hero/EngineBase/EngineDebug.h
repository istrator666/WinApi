#pragma once
#include <Windows.h>
#include <assert.h>
#include <string>
#include <string_view>

/// <summary>
/// LeakCheck -> 해제되지 않은 동적할당 메모리 체크, MagBoxAssert->특정 조건이 충족되지 않으면 오류 메시지 출력 및 프로그램 중단
/// MessageBox는 C 스타일 문자열을 인자로 받는데, std::string은 C++ 문자열 클래스이기 때문에 C 스타일 문자로 변환이 필요하고 c_str()을 사용해서 char* C 스타일 문자열로 변환한다.
/// char이 아닌 char*으로 받는 이유는 문자열이기 때문.
/// </summary>
namespace EngineDebug
{
	#define LeakCheck _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	#define MsgBoxAssert(Value) \
	std::string ErrorText = std::string(Value); \
	MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);

	void OutPutDebugText(std::string_view _DebugText);
}