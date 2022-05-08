#include <iostream>
#include "lock.h"



int main() {

	// text.txt 파일을 out.txt 파일로 암호화합니다.
	// encryptor::Lock("text.txt", "out.txt");

	std::string inputPath;
	std::string outputPath;
	char buffer[2048];
	
	std::cout << "입력파일 이름을 입력하세요 : \r\n";
	std::cin.getline(buffer, 2048);
	inputPath = *(new std::string(buffer));
	std::cout << "출력파일 이름을 입력하세요 : \r\n";
	std::cin.getline(buffer, 2048);
	outputPath = *(new std::string(buffer));

	encryptor::Lock(inputPath,outputPath);

	return 0;
}

