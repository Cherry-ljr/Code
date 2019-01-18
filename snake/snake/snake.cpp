#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;


const int maxn = 20, maxm = 40;

char mpt[maxn][maxm];
int sx = 5, sy = 5;
int foodx, foody;
int head, tail;

struct node{
	int x, y;
}snake[100];


void Init(){
	
	head = tail = 0;
	for (int i = 0; i < maxn; i++){
	for (int j = 0; j < maxm; j++)
	{
		if (i == 0 || i == maxn - 1||j == 0 || j == maxm - 1)
			mpt[i][j] = '*';
		else mpt[i][j] = ' ';
	}
	}
	snake[tail].x = sx;
	snake[tail].y = sy--;
	tail++;
	snake[tail].x = sx;
	snake[tail].y = sy;
	tail++;

	//mpt[sx][sy] = 'S';

	foodx = rand() % maxn;
	foody = rand() % maxm;
	mpt[foodx][foody] = 'O';
}

void  print(){


	for (int i = 0; i < maxn; i++){
		for (int j = 0; j < maxm; j++)
		{
			if (i == 0 || i == maxn - 1 || j == 0 || j == maxm - 1)
				mpt[i][j] = '*';
			else mpt[i][j] = ' ';
		}
	}

	for (int i = 0; i < tail; i++){
		mpt[snake[i].x][snake[i].y] = 'S';
	}

	mpt[foodx][foody] = '0';
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxm; j++)
		{
			cout << mpt[i][j];
		}
		cout << endl;
	}
}
void Direct(int dir){
	//mpt[sx][sy] = ' ';
	for (int i = tail - 1; i>head; i--){
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;

	}
	if (dir == 0) snake[head].x--;	
	else if (dir == 1)snake[head].x++;
	else if (dir == 2) snake[head].y--;
	else snake[head].y++;
	//mpt[sx][sy] = 'S';
	if (snake[head].x == foodx&&snake[head].y == foody){
		foodx = rand() % maxn;
		foody = rand() % maxm;
		tail++;
	}
	if (snake[head].x<0 || snake[head].x>maxn - 1 || snake[head].y<0 || snake[head].y>maxm - 1){
		cout << "game over£¡";
		exit(0);
	}
}



int main(){
	int dir = 3;
	char ch = ' ';
	Init();
	while (1){
		
		print();
		Sleep(500);
		system("cls");
		while (kbhit()){
			ch = getch();
			if (ch == 'w') dir = 0;
			if (ch == 's') dir = 1;
			if (ch == 'a') dir = 2;
			if (ch == 'd') dir = 3;
		}
		Direct(dir);

	}
	return 0;
}
