#include <iostream>

using namespace std;

const int maxn=100;
const int INF=1000000000;

int G[maxn][maxn];
int d[maxn];
bool vis[maxn]={false};

int prim(int n){
    fill(d,d+maxn,INF);
    d[0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        
        if(u==-1) return -1;
        vis[u]=true;
        ans+=d[u];
        
        for(int j=0;j<n;j++){
            if(vis[j]==false&&G[u][j]!=INF&&G[u][j]<d[j]){
                d[j]=G[u][j];
            }
        }
    }
    
    return ans;
}

int main(int argc, char **argv)
{
    int n,m;
    cin>>n>>m;
    fill(G[0],G[0]+maxn*maxn,INF);
    
    int u,v,w;
    
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        G[u][v]=G[v][u]=w;
    }
    
    int ans=prim(n);
    
    cout<<ans<<endl;

    return 0;
}

