#include <iostream>

using namespace std;

const int maxn=30;

int n,v,maxValue=0;
int w[maxn],c[maxn];


void DFS(int index,int sumW,int sumC){
    if(index==n){
        return;
    }
    DFS(index+1,sumW,sumC);
	
	//剪枝算法
    if(sumW+w[index]<=v){
        if(sumC+c[index]>maxValue)
            maxValue=sumC+c[index];
        DFS(index+1,sumW+w[index],sumC+c[index]);
    }
}


int main(int argc, char **argv)
{
    cin>>n>>v;
    
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    
    DFS(0,0,0);
    
    cout<<maxValue<<endl;
    
    
    return 0;
}

