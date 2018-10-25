#include <iostream>
#include <cmath>

using namespace std;

//判断素数1
bool isPrime(int n){
    if(n<=1) return false;
    int sqr=(int)sqrt(n);
    
    for(int i=2;i<=sqr;i++)
        if(n%i==0) return false;
    
    return true;
}
//判断素数2
bool isPrime2(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    
    return true;
}


//打印一百以内的素数表
const int maxn=101;
int prime[maxn],pNum=0;

bool p[maxn]={0};

void Find_prime(){
    for(int i=2;i<maxn;i++){
        if(!p[i]){
            prime[pNum++]=i;
            for(int j=i+i;j<maxn;j+=i)
                p[j]=true;
        }
    }
}

void print_prime(){
    Find_prime();
    for(int i=0;i<pNum;i++)
        cout<<prime[i]<<" ";
    cout<<endl;
}
/*
void Find_prime1(){
    for(int i=2;i<maxn;i++){
        if(!p[i]){
            for(int j=i+i;j<maxn;j+=i)
                p[j]=true;
        }
    }
}*/

int main(int argc, char **argv)
{
    
    print_prime();

    return 0;
}

