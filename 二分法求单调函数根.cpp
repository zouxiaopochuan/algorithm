#include <iostream>

using namespace std;

const double eps=1e-5;

double square(double x){
    return x*x;
}

double calSqrt(double left,double right,double x){
    double mid;
    while(right-left>eps){
        mid=(right+left)/2;
        if(square(mid)>x) right=mid;
        else left=mid;
    }
    
    return mid;
}

int main(int argc, char **argv)
{
    
    int n;
    while(cin>>n){
        cout<<calSqrt(0,n,n)<<endl;
    }
   
    return 0;
}

