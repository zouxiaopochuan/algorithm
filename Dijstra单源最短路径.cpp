#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=100;
const int INF=1000000000;

int G[maxn][maxn];
int d[maxn];
bool vis[maxn];

void Dijkstra(int s,int n){
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&G[u][j]!=INF&&d[u]+G[u][j]<d[j]){
                d[j]=d[u]+G[u][j];
            }
        }
    }
}

int main(int argc, char **argv)
{
    int n,m,s;//顶点个数，边数，起始点
    int u,v,w;
    cin>>n>>m>>s;
    
    fill(G[0],G[0]+maxn*maxn,INF);
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        G[u][v]=w;
    }
    
    Dijkstra(s,n);
    
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    
    cout<<endl;
    
}

