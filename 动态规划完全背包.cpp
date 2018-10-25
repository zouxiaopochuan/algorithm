#include <iostream>
using namespace std;

const int maxn=100;
const int maxv=1000;

int w[maxn],c[maxn],dp[maxv];

int main(int argc, char **argv)
{
    int n,v;
    cin>>n>>v;
    fill(dp,dp+maxn,0);
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=v;j++){
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    
    cout<<dp[v]<<endl;
 
 
    return 0;
}

