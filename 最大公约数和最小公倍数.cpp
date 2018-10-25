#include <iostream>

using namespace std;

//最大公约数
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

//最小公倍数
int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(int argc, char **argv)
{
    int a,b;
    while(cin>>a>>b){
        cout<<gcd(a,b)<<endl;
        
        cout<<lcm(a,b)<<endl;
    }

    return 0;
}

