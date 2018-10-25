#include <iostream>

using namespace std;

typedef long long LL;
LL binaryPow(LL a,LL b,LL m){
    if(b==0) return 1;
    if(b%2==0){
        LL temp=binaryPow(a,b>>=1,m);
        return temp*temp%m;
    }
    return a*binaryPow(a,b-1,m);
}

int main(int argc, char **argv)
{
    long long a,b,m;
    while(cin>>a>>b>>m){
        cout<<a<<b<<m<<endl;
        cout<<binaryPow(a,b,m)<<endl;
    }    
    return 0;
}

