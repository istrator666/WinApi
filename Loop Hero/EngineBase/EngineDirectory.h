#pragma once
#include "EnginePath.h"
#include <list>

class UEngineFile;
// ���� : Ư�����丮���� ���� �˻� ��� ����
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

	/// <summary>
	/// Ư�� Ȯ���� ���� Ž�� �Լ�
	/// </summary>
	/// <param name="_Ext"> Ȯ���� �Է�(�� ���̸� ���� Ž��) ex) .png. bmp </param>
	/// <param name="_Recursive"> true�� ���� ���丮���� ��� Ž�� </param>
	/// <returns></returns>
	std::list<UEngineFile> AllFile(std::vector<std::string> _Ext = std::vector<std::string>(), bool _Recursive = false);

protected:

private:
	/// <summary>
	/// ��ͷ� ������ �˻��ϴ� �Լ�
	/// </summary>
	/// <param name="_Path"> ��� �Է� </param>
	/// <param name="_Result"> �˻��� ���� ���� </param>
	/// <param name="_Ext"> Ȯ���� �Է�(�� ���̸� ���� Ž��) ex) .png. bmp </param>
	/// <param name="_Recursive"> true�� ���� ���丮���� ��� Ž�� </param>
	void AllFileRecursive(const std::string_view _Path, std::list<UEngineFile>& _Result, std::vector<std::string> _Ext = std::vector<std::string>(), bool _Recursive = false);
};

