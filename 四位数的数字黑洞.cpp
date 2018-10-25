#include <iostream>
#include <algorithm>

using namespace std;

int num[5];

bool cmp(int a,int b){
    return a>b;
}

int toNum(int *num,int length){
    int ans=0;
    for(int i=0;i<length;i++){
        ans=ans*10+num[i];
    }
    return ans;
}

int main(int argc, char **argv)
{
    int n;
    cin>>n;
    
    while(n!=6174){
    
        num[0]=n/1000;
        num[1]=(n%1000)/100;
        num[2]=(n%100)/10;
        num[3]=n%10;
    
        sort(num,num+4);
        int a=toNum(num,4);
    
        sort(num,num+4,cmp);
        int b=toNum(num,4);
        
        n=b-a;
        
        cout<<b<<"-"<<a<<"="<<n<<endl;
        if(n==0) break;
        
    }
    
    
    return 0;
}

