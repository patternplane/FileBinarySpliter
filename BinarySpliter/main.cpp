#include <iostream>
#include "lock.h"



int main() {

	// text.txt ������ out.txt ���Ϸ� ��ȣȭ�մϴ�.
	// encryptor::Lock("text.txt", "out.txt");

	std::string inputPath;
	std::string outputPath;
	char buffer[2048];
	
	std::cout << "�Է����� �̸��� �Է��ϼ��� : \r\n";
	std::cin.getline(buffer, 2048);
	inputPath = *(new std::string(buffer));
	std::cout << "������� �̸��� �Է��ϼ��� : \r\n";
	std::cin.getline(buffer, 2048);
	outputPath = *(new std::string(buffer));

	encryptor::Lock(inputPath,outputPath);

	return 0;
}

