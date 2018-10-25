#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake{
    double weight;
    double value;
    double price;
}cake[1001];

bool cmp(mooncake a,mooncake b){
    return a.price>b.price;
}

int main(int argc, char **argv)
{
    int n,d;
    cin>>n>>d;
    
    
    for(int i=0;i<n;i++)
        cin>>cake[i].weight;
    for(int i=0;i<n;i++){
        cin>>cake[i].value;
        cake[i].price=cake[i].value/cake[i].weight;
    }
    
    sort(cake,cake+n,cmp);
    
    double sum=0;
    
    for(int i=0;i<n;i++){
        if(d>cake[i].weight){
            sum+=cake[i].value;
            d-=cake[i].weight;
        }else{
            sum+=d*cake[i].price;
            d=0;
            break;
        }
    }
    
    cout<<sum<<endl;
   
    return 0;
}

