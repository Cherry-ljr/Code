#include<iostream>
using namespace std;
 
int Gcd(int a,int b)
{
    while(b != 0)
    {
        int r = b;
        b = a%b;
        a = r;
    }
    return a;
}
 
int main(){
    int m,n;
    while(cin>>m>>n && m!=0 &&n!=0){
       if(n%2!=0)cout<<"N"<<endl;
       else {
        int x=Gcd(m,n);
        if((n/2)%x==0) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
       }
 
    }
 
 
return 0;
}