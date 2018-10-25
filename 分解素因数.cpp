#include <iostream>
#include <cmath>

using namespace std;

const int maxn = 10010;
int prime[maxn],prime_num=0;
bool p[maxn]={0};

struct factor{
    int x,cnt;
}fac[20];

void Find_prime(){
    for(int i=2;i<maxn;i++){
        if(!p[i]){
            prime[prime_num++]=i;
            for(int j=i*i;j<maxn;j+=i){
                p[j]=true;
            }
        }
    }
}

void print_prime(){
    Find_prime();
    for(int i=0;i<prime_num;i++){
        cout<<prime[i]<<" ";
    }
    cout<<endl;
}

int Prime_factor(int n){
    int factor_num=0;
    int temp=sqrt(n);
    for(int i=0;prime[i]<temp;i++){
        if(n%prime[i]==0){
            fac[factor_num].x=prime[i];
            fac[factor_num].cnt++;
            n/=prime[i];
            while(n%prime[i]==0){
                fac[factor_num].cnt++;
                n/=prime[i];
            }
            factor_num++;
        }
    }
    if(n>1){
        fac[factor_num].x=n;
        fac[factor_num].cnt++;
        factor_num++;
    }
        
    return factor_num;
    
}


int main(int argc, char **argv)
{
    Find_prime();
    
    int n;
    while(cin>>n){
        
        for(int i=0;i<20;i++){
            fac[i].x=0;
            fac[i].cnt=0;
        }
        
        int factor_num=Prime_factor(n);
        
        cout<<n<<"=";
        for(int i=0;i<factor_num-1;i++){
            cout<<fac[i].x;
            if(fac[i].cnt>1)
                cout<<"^"<<fac[i].cnt;
            cout<<"*";
        }
        cout<<fac[factor_num-1].x;
        if(fac[factor_num-1].cnt>1)
            cout<<"^"<<fac[factor_num-1].cnt;
        
        cout<<endl;
        
    }
    return 0;
}

