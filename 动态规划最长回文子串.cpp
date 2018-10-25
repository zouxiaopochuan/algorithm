#include <iostream>
#include <string>

using namespace std;

const int maxn=100;
int dp[maxn][maxn];

string str;


int main(int argc, char **argv)
{
    fill(dp[0],dp[0]+maxn*maxn,0);
    cin>>str;
    int len=str.length();
    
    int ans=1;
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1&&str[i]==str[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }
    
    for(int L=2;L<len;L++){
        for(int i=0;i+L<len;i++){
            if(str[i]==str[i+L]&&dp[i+1][i+L-1]){
                dp[i][i+L]=1;
                ans=L+1;
            }
        }
    }

    cout<<ans<<endl;
 
    return 0;
}

