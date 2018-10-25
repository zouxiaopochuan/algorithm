#include <iostream>
using namespace std;

const int maxn=100;
const int maxv=1000;

int w[maxn];
int c[maxn];
int dp[maxv];

int main(int argc, char **argv)
{
    int n,v;
    cin>>n>>v;
    
    fill(dp,dp+maxv,0);
    
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=v;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    
    for(int i=0;i<=v;i++){
        cout<<dp[i]<<endl;
    }
    
    
 
    return 0;
}

