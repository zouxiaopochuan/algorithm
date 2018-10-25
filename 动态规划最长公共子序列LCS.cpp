#include <iostream>
#include <string>

using namespace std;

const int maxn=100;

int dp[maxn][maxn];

string str1;
string str2;

int main(int argc, char **argv)
{
    cin>>str1>>str2;
    int length1=str1.length();
    int length2=str2.length();
    
    for(int i=0;i<=length1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=length2;i++){
        dp[i][0]=0;
    }
    
    for(int i=1;i<=length1;i++){
        for(int j=1;j<=length2;j++){
            if(str1[i]==str2[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    cout<<dp[length1][length2]<<endl;

 
    return 0;
}

