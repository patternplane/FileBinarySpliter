#include <iostream>
#include "lock.h"



int main() {

	// text.txt ������ out.txt ���Ϸ� ��ȣȭ�մϴ�.
	// encryptor::Lock("text.txt", "out.txt");

	std::string inputPath;
	std::string outputPath;
	
	std::cout << "�Է����� �̸��� �Է��ϼ��� : \r\n";
	std::cin >> inputPath;
	std::cout << "������� �̸��� �Է��ϼ��� : \r\n";
	std::cin >> outputPath;

	encryptor::Lock(inputPath,outputPath);

	return 0;
}

