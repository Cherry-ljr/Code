#include <iostream>
using namespace std;

int main() {
	char a[105];
	char b[105];
	int c[105] = { 0 };
	//scanf("%s%s", a, b);
	cin >> a >> b;
	int lena = strlen(a);
	int lenb = strlen(b);
	int k = 0;
	for (int i = lenb - 1; i >= 0; i--) {
		for (int j = lena - 1; j >= 0; j--) {
			int valb = b[i] - '0';
			int vala = a[j] - '0';
			int valc = valb * vala;
			int pos = k + lena - 1 - j;
			c[pos] += valc;
			c[pos + 1] += c[pos] / 10;
			c[pos] = c[pos] % 10;
		}
		k++;
	}
	if (c[lena + lenb - 1] != 0) printf("%d", c[lena + lenb - 1]);
	for (int i = lena + lenb - 2; i >= 0; i--) {
		printf("%d", c[i]);
	}
	printf("\n");

	return 0;
}