#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

int main(){
    char s1[500],s2[500];
    cin>>s1>>s2;
    int m=strlen(s1);
    int n=strlen(s2);
    int s[1000]={0};
    for(int i=0;i<m/2;i++)
    {
        swap(s1[i],s1[m-1-i]);
    }
    for(int i=0;i<n/2;i++)
    {
        swap(s2[i],s2[n-1-i]);
    }
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int t1=(s1[i]-'0')*(s2[j]-'0');
            s[i+j] += t1;
            int w = s[i+j]/10;
            s[i+j] %= 10;
            s[i+j+1] += w;
        }
            /*
            if(t1>9)
            {
                int x1=t1/10;
                int y1=t1%10;
                s[k]=s[k]+y1+'0';
                s[k+1]=s[k+1]+x1+'0';
            }
            else
            {   int t2=s[k]+t1-'0';
                if(t2<9)
                    s[k]=t2+'0';
                else {
                    int x2=t2/10;
                    int y2=t2%10;
                    s[k]=s[k]+y2+'0';
                    s[k+1]=s[k+1]+x2+'0';
                }
            }
        }
        k++;
        */
    }
    int zero = 0;
    for(int k=m+n-1;k>=0;k--) {
        if (zero == 0 && s[k] == 0) continue;
        if (s[k] != 0) {
            zero = 1;
            cout<<s[k];
        }
    }
    cout << endl;
    return 0;
}
