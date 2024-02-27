#pragma once
#include "EnginePath.h"
#include <list>

class UEngineFile;
// 설명 : 특정디렉토리에서 파일 검색 기능 제공
class UEngineDirectory : public UEnginePath
{
public:
	// constrcuter destructer
	UEngineDirectory();
	UEngineDirectory(const UEnginePath& _Path);
	~UEngineDirectory();

	// delete Function
	//UEngineDirectory(const UEngineDirectory& _Other) = delete;
	//UEngineDirectory(UEngineDirectory&& _Other) noexcept = delete;
	//UEngineDirectory& operator=(const UEngineDirectory& _Other) = delete;
	//UEngineDirectory& operator=(UEngineDirectory&& _Other) noexcept = delete;

	void MoveToSearchChild(std::string_view _Path);

	/// <summary>
	/// 특정 확장자 파일 탐색 함수
	/// </summary>
	/// <param name="_Ext"> 확장자 입력(빈 값이면 전부 탐색) ex) .png. bmp </param>
	/// <param name="_Recursive"> true면 하위 디렉토리까지 모두 탐색 </param>
	/// <returns></returns>
	std::list<UEngineFile> AllFile(std::vector<std::string> _Ext = std::vector<std::string>(), bool _Recursive = false);

	std::list<UEngineDirectory> AllDirectory(bool _Recursive = false);

	UEngineFile NewFile(std::string_view FileName);

protected:

private:

	void AllDirectoryRecursive(const std::string_view _Path, std::list<UEngineDirectory>& _Result, bool _Recursive = false);

	/// <summary>
	/// 재귀로 파일을 검색하는 함수
	/// </summary>
	/// <param name="_Path"> 경로 입력 </param>
	/// <param name="_Result"> 검색한 파일 저장 </param>
	/// <param name="_Ext"> 확장자 입력(빈 값이면 전부 탐색) ex) .png. bmp </param>
	/// <param name="_Recursive"> true면 하위 디렉토리까지 모두 탐색 </param>
	void AllFileRecursive(const std::string_view _Path, std::list<UEngineFile>& _Result, std::vector<std::string> _Ext = std::vector<std::string>(), bool _Recursive = false);

};

