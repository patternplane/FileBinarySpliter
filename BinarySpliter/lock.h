#pragma once
#include <iostream>

class encryptor {
private:
	/// <summary>
	/// ��ȣȭ�� Ȱ��� key�Դϴ�.
	/// </summary>
	static int key;

	/// <summary>
	/// ��ȣȭ �˰����� ���� ���� �� ������ ��ȣȭ�մϴ�.
	/// </summary>
	/// <param name="buffer">
	/// ���ϳ��� ���� ����
	/// </param>
	/// <param name="contentSize">
	/// ���ۿ� ��� ���ϳ����� ��
	/// </param>
	static void encoding(char* buffer, const int contentSize);

	/// <summary>
	/// ��ȣȭ�� ���� key�� �޾ƿɴϴ�.
	/// </summary>
	static void getKey();
public:
	/// <summary>
	/// ������ ��ȣȭ/��ȣȭ �ϴ� �Լ�
	/// </summary>
	/// <param name="inputFilePath">
	/// �Է� ���� ���
	/// </param>
	/// <param name="outputFilePath">
	/// ��� ���� ���
	/// </param>
	static void Lock(std::string inputFilePath, std::string outputFilePath);

};