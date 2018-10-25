#include <iostream>

using namespace std;

const int maxn=1000;

int A[maxn],dp[maxn];


int main(int argc, char **argv)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    int ans=-1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>=A[j]&&(dp[j]+1>dp[i])){
                dp[i]=dp[j]+1;
            }
        }
        ans=max(ans,dp[i]);
    }
    
    cout<<ans<<endl;
 
    return 0;
}

