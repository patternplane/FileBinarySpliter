#include <iostream>
#include <fstream>

void Lock(std::string, std::string);

int main() {

	Lock("out.txt","minecraft2.exe");
	//Lock("out.txt", "text.txt");

	return 0;
}

void Lock(std::string inputFilePath, std::string outputFilePath) {

	unsigned char key;
	std::cout << "0~255 사이의 열쇠를 입력하세요.\n";
	std::cin >> key;

	std::ifstream fileIn(inputFilePath, std::ios::binary);
	std::ofstream fileOut(outputFilePath, std::ios::binary);

	const int BUFFER_SIZE = 1024;
	char buffer[BUFFER_SIZE];

	int readCount;

	if (fileIn.is_open()) {
		while (true) {
			readCount = fileIn.read(buffer, BUFFER_SIZE).gcount();
			if (readCount == 0)
				break;

			for (int i = 0; i < BUFFER_SIZE; i++)
				buffer[i] ^= (key++);
			fileOut.write(buffer, readCount);
		}
	}

	fileIn.close();
	fileOut.close();
}
