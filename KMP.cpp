#include<iostream>
#include<cstring>
using namespace std;


char s[80];
char t[20];
int Next[20] = {0};

void getNext(){
	int len = strlen(t);
	for (int i = 1; i < len; i++){
		if (t[i] == t[0]) Next[i] = 1;
		if (t[Next[i - 1]] == t[i]) Next[i] = Next[i - 1] + 1;
	}
}
void kmp(){
	int lens = strlen(s);
	int lent = strlen(t);
	int j = 0;
	int i;
	for (i = 0; i < lens; i++){
		if (s[i] == t[j]) 
		{
			if (j == lent - 1) {
				cout << i - lent+1 << endl;;
				break;
			}
			j++; continue;
		}
		else {
			if (j == 0) continue;
			j = Next[j-1]; i--; 
		}
	}
	if (i == lens) {
		cout << "Not Find" << endl;
	}
}
int main(){

	cin >> s >> t;
	getNext();
	kmp();

	return 0;
}