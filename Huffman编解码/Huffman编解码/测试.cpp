
#include <stdio.h>
#include"HuffmanTree.cpp"


int main() {
	HuffmanTree htree(4);
	char *str = "abcd";
	int weight[] = { 7, 5, 2, 4 };
	htree.create(str, weight);
	htree.output();

	//���Ա���
	char hcode[100] = { 0 };
	htree.encode("dad", hcode);
	printf("������Ϊ��%s\n", hcode);

	//���Խ���
	char dcode[100] = { 0 };
	htree.decode(hcode, dcode);
	printf("������Ϊ��%s\n", dcode);


	htree.loadFromFile();
	htree.saveToFile();

	return 0;
}
