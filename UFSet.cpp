#include<iostream>

const int N=110;
int father[N];

//并查集
void init(int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    
}

int findFather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    
    return x;
}

void Union(int a, int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb){
        father[fa]=fb;
    }
}
























