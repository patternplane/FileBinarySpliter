#include "lock.h"
#include <fstream>
#include <stdio.h>

int encryptor::key = 1;

void encryptor::Lock(std::string inputFilePath, std::string outputFilePath) {

	// Ű �� �Է�
	getKey();

	FILE* fileIn;
	FILE* fileOut;
	fopen_s(&fileIn, inputFilePath.c_str(), "rb");
	fopen_s(&fileOut, outputFilePath.c_str() , "wb");
	const int BUFFER_SIZE = 1024*1024*128;
	static char buffer[BUFFER_SIZE];

	int currentDoneMB = 0;
	
	int readCount;
	while (true) {
		readCount = fread(buffer, sizeof(char), BUFFER_SIZE, fileIn);
		if (readCount == 0)
			break;

		// ���� ������ ��ȣȭ
		encoding(buffer,readCount);

		fwrite(buffer, sizeof(char), readCount, fileOut);
		std::cout << (currentDoneMB += readCount/1024/1024) << "MB �Ϸ�" << std::endl;
	}

	fclose(fileIn);
	fclose(fileOut);
}

void encryptor::encoding(char* buffer, const int contentSize) {
	for (int i = 0; i < contentSize; i++)
		buffer[i] ^= (encryptor::key++);
}

void encryptor::getKey() {
	std::cout << "0~255 ������ ���踦 �Է��ϼ���.\n";
	std::cin >> encryptor::key;
}