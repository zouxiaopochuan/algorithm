#include <iostream>

using namespace std;

const int MAXN=10010;
bool hashTable[MAXN]={false};

int main(int argc, char **argv)
{
    int n,m;
    int x;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>x;
        hashTable[x]=true;
    }
    
    for(int i=0;i<m;i++){
        cin>>x;
        if(hashTable[x])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
  
    
    return 0;
}

