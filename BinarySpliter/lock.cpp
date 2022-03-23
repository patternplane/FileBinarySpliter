#include "lock.h"
#include <fstream>

int encryptor::key = 1;

void encryptor::Lock(std::string inputFilePath, std::string outputFilePath) {

	// Ű �� �Է�
	getKey();

	std::ifstream fileIn(inputFilePath, std::ios::binary);
	std::ofstream fileOut(outputFilePath, std::ios::binary);
	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE];
	
	if (fileIn.is_open()) {
		int readCount;
		while (true) {
			readCount = fileIn.read(buffer, BUFFER_SIZE).gcount();
			if (readCount == 0)
				break;

			// ���� ������ ��ȣȭ
			encoding(buffer,readCount);

			fileOut.write(buffer, readCount);
		}
	}

	fileIn.close();
	fileOut.close();
}

void encryptor::encoding(char* buffer, const int contentSize) {
	for (int i = 0; i < contentSize; i++)
		buffer[i] ^= (encryptor::key++);
}

void encryptor::getKey() {
	std::cout << "0~255 ������ ���踦 �Է��ϼ���.\n";
	std::cin >> encryptor::key;
}