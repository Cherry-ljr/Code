
#include <stdio.h>
#include"HuffmanTree.cpp"


int main() {
	HuffmanTree htree(4);
	char *str = "abcd";
	int weight[] = { 7, 5, 2, 4 };
	htree.create(str, weight);
	htree.output();

	//测试编码
	char hcode[100] = { 0 };
	htree.encode("dad", hcode);
	printf("编码结果为：%s\n", hcode);

	//测试解码
	char dcode[100] = { 0 };
	htree.decode(hcode, dcode);
	printf("解码结果为：%s\n", dcode);


	htree.loadFromFile();
	htree.saveToFile();

	return 0;
}
