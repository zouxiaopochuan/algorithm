#include <iostream>

using namespace std;

const int maxn=100;

/*long long dp[maxn];

long long Fib(int n){
    if(n==0||n==1) return 1;
    
    if(dp[n]!=-1) return dp[n];
    else{
        dp[n]=Fib(n-1)+Fib(n-2);
        return dp[n];
    }
}*/

long long Fib(int n){
    if(n==0||n==1) return 1;
    
    int a=1;
    int b=1;
    int temp=0;
    for(int i=2;i<=n;i++){
        temp=a+b;
        b=a;
        a=temp;
    }
    
    return temp;
}


int main(int argc, char **argv)
{
    int n;
    //fill(dp,dp+maxn,-1);
    while(cin>>n)
        cout<<Fib(n)<<endl;

    return 0;
}

