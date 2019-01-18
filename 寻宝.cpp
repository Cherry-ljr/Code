#include<iostream>
using namespace std;
 
int m, n;
int mpt[1000][1000] = { 0 };
int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
 
void find(int a,int b){
    int min = 9999;
    int index1, index2;
    index1 = index2 = 0;
    for (int i = a; i < m; i++){
        for (int j = b; j < n; j++){
            if (mpt[i][j] == 0) 
              { cout << i+1 << " " << j+1 << endl;
                 return;
               }
            else {
                for (int k = 0; k < 4; k++){
                    if (mpt[i + dir[k][0]][j + dir[k][1]] < min)
                    {
                        index1 = i + dir[k][0];
                        index2 = j + dir[k][1];
                        min = mpt[index1][index2];
                         
                    }
 
                }
            }
        }
    }
    find(index1,index2);
 
}
int main(){
 
    while (cin >> m >> n && m > 0 && n > 0){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> mpt[i][j];
 
            }   
        }
    find(0, 0);
    }
 
 
    return 0;
}