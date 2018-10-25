#include <iostream>
#include <vector>

using namespace std;

const int maxn=30;

int sq[maxn];
bool sign[maxn];


void DFS(int index,int n){
    if(index==n){
        for(int i=0;i<n;i++){
            if(sign[i])
                cout<<sq[i]<<" ";
        }
        cout<<endl;
        return;
    }
        
    sign[index]=true;
    DFS(index+1,n);
    sign[index]=false;
    DFS(index+1,n);
}

int main(int argc, char **argv)
{
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>sq[i];
        }
        
        DFS(0,n);
    }
    
    return 0;
}

