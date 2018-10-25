#include <iostream>

using namespace std;

const int maxn=100;
int A[maxn],dp[maxn];

int main(int argc, char **argv)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    dp[0]=A[0];
    
    for(int i=1;i<n;i++){
        dp[i]=max(A[i],dp[i-1]+A[i]);
    }
    int k=0;
    for(int i=0;i<n;i++){
        if(dp[i]>dp[k])
            k=i;
    }
    
    cout<<dp[k]<<endl;
    return 0;
}

