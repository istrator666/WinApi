#include <Windows.h>
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineWindow.h>
#include <Contents\LoopHero.h>

//ENGINESTART(LoopHeroContentsCore)

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	LeakCheck;
	LoopHeroContentsCore NewUserCore = LoopHeroContentsCore();
	NewUserCore.EngineStart(hInstance);
}