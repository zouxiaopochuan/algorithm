#include <iostream>
#include <string>

using namespace std;


//有几个PAT

const int mod=1000000007;

const int maxn=100010;

int leftNumP[maxn]={0};

int main(int argc, char **argv)
{
    string str;
    while(cin>>str){
        int p_num=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='P') p_num++;
            leftNumP[i]=p_num;
        }
        
        int ans=0,T_num=0;
        
        for(int i=str.length()-1;i>=0;i--){
            if(str[i]=='T') T_num++;
            if(str[i]=='A'){
                ans=(ans+leftNumP[i]*T_num)%mod;
            }
        }
        
        
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}

