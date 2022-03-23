#pragma once
#include <iostream>

class encryptor {
private:
	/// <summary>
	/// 암호화에 활용될 key입니다.
	/// </summary>
	static int key;

	/// <summary>
	/// 암호화 알고리즘을 통해 버퍼 한 단위를 암호화합니다.
	/// </summary>
	/// <param name="buffer">
	/// 파일내용 버퍼 조각
	/// </param>
	/// <param name="contentSize">
	/// 버퍼에 담긴 파일내용의 양
	/// </param>
	static void encoding(char* buffer, const int contentSize);

	/// <summary>
	/// 암호화에 사용될 key를 받아옵니다.
	/// </summary>
	static void getKey();
public:
	/// <summary>
	/// 파일을 암호화/복호화 하는 함수
	/// </summary>
	/// <param name="inputFilePath">
	/// 입력 파일 경로
	/// </param>
	/// <param name="outputFilePath">
	/// 출력 파일 경로
	/// </param>
	static void Lock(std::string inputFilePath, std::string outputFilePath);

};