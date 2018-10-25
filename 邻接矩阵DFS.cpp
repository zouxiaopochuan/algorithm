#include <iostream>

using namespace std;

const int maxn=100;
const int INF=100000000;

int G[maxn][maxn];
int vis[maxn]={false};

int n,k;

void DFS(int x){
    vis[x]=true;
    for(int i=1;i<=n;i++){
        if(vis[i]==false&&G[x][i]!=INF)
            DFS(i);
    }
}

int DFSTravel(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            DFS(i);
            ans++;
        }
    }
    
    return ans;
}


int main(int argc, char **argv)
{
    while(cin>>n>>k){
        
        fill(G[0],G[0]+maxn*maxn,INF);
        
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            G[a][b]=G[b][a]=1;
        }
        
        cout<<DFSTravel()<<endl;
    }
    return 0;
}

