#include "Level.h"
#include "Actor.h"
#include <EngineBase/EngineDebug.h>

ULevel::ULevel()
{
}

ULevel::~ULevel()
{
	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;
		for (AActor* Actor : ActorList)
		{
			if (nullptr == Actor)
			{
				continue;
			}

			delete Actor;
			Actor = nullptr;
		}
	}
	AllActor.clear();
}

void ULevel::LevelTick(float _DeltaTime)
{
	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;
		for (AActor* Actor : ActorList)
		{
			Actor->ActiveUpdate(_DeltaTime);
			Actor->DestroyUpdate(_DeltaTime);
			if (false == Actor->IsActive())
			{
				continue;
			}

			Actor->Tick(_DeltaTime);
		}
	}
}

void ULevel::LevelRender(float _DeltaTime)
{
	for (std::pair<const int, std::list<UImageRenderer*>>& OrderListPair : Renderers)
	{
		std::list<UImageRenderer*>& RendererList = OrderListPair.second;
		for (UImageRenderer* Renderer : RendererList)
		{
			// Ranged for는 중간에 리스트의 원소의 개수가 변경되면 굉장히 불안정해지고
			// 치명적인 오류가 발생할 가능성이 높아진다.
			// 절대로 파괴하지 
			if (false == Renderer->IsActive())
			{
				continue;
			}

			Renderer->Render(_DeltaTime);
		}
	}

}

void ULevel::LevelRelease(float _DeltaTime)
{

	for (std::pair<const int, std::list<UImageRenderer*>>& OrderListPair : Renderers)
	{
		std::list<UImageRenderer*>& RendererList = OrderListPair.second;

		std::list<UImageRenderer*>::iterator StartIter = RendererList.begin();
		std::list<UImageRenderer*>::iterator EndIter = RendererList.end();

		for (; StartIter != EndIter; )
		{
			UImageRenderer* Renderer = StartIter.operator*();

			if (false == Renderer->IsDestroy())
			{
				++StartIter;
				continue;
			}
			StartIter = RendererList.erase(StartIter);
		}
	}

	for (std::pair<const int, std::list<AActor*>>& OrderListPair : AllActor)
	{
		std::list<AActor*>& ActorList = OrderListPair.second;

		std::list<AActor*>::iterator StartIter = ActorList.begin();
		std::list<AActor*>::iterator EndIter = ActorList.end();

		for (; StartIter != EndIter;)
		{
			AActor* Actor = StartIter.operator*();

			if (nullptr == Actor)
			{
				MsgBoxAssert("Actor가 nullptr인 경우가 존재했습니다");
				return;
			}

			if (false == Actor->IsDestroy())
			{
				++StartIter;
				continue;
			}

			delete Actor;
			Actor = nullptr;
			StartIter = ActorList.erase(StartIter);
		}
	}
}

void ULevel::ActorInit(AActor* _NewActor)
{
	_NewActor->SetWorld(this);
	_NewActor->BeginPlay();
}
