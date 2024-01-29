#pragma once
#include <string>
#include <string_view>
#include <map>


class UImage;
// Ό³Έν : 
class UEngineResourcesManager
{
public:
	// delete Function
	UEngineResourcesManager(const UEngineResourcesManager& _Other) = delete;
	UEngineResourcesManager(UEngineResourcesManager&& _Other) noexcept = delete;
	UEngineResourcesManager& operator=(const UEngineResourcesManager& _Other) = delete;
	UEngineResourcesManager& operator=(UEngineResourcesManager&& _Other) noexcept = delete;

	static UEngineResourcesManager& GetInst()
	{
		static UEngineResourcesManager Inst = UEngineResourcesManager();
		return Inst;
	}

	UImage* LoadImg(std::string_view _Path);

	UImage* FindImg(std::string_view _Name);



protected:

private:
	// constrcuter destructer
	UEngineResourcesManager();
	~UEngineResourcesManager();

	std::map<std::string, UImage*> Images;

};

