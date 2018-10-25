#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=100;
const int INF=1000000000;

int G[maxn][maxn],cost[maxn][maxn];
bool vis[maxn]={false};
int d[maxn];
int c[maxn];

int pre[maxn];

void Dijkstra(int s,int n){
    fill(d,d+maxn,INF);
    
    fill(c,c+maxn,INF);
    
    for(int i=0;i<n;i++) pre[i]=i;
    
    d[s]=0;
    c[s]=0;
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
            if(vis[j]==false&&G[u][j]!=INF){
                if(d[u]+G[u][j]<d[j]){
                    d[j]=G[u][j]+d[u];
                    c[j]=cost[u][j]+c[u];
                    pre[j]=u;
                }else if(d[u]+G[u][j]==d[j]&&c[u]+cost[u][j]<c[j]){
                    c[j]=cost[u][j]+c[u];
                    pre[j]=u;
                }
            }
        }
    }
}

void DFS(int ed){
    if(pre[ed]==ed){
        cout<<ed<<" ";
        return;
    }
    
    DFS(pre[ed]);
    cout<<ed<<" ";
}



int main(int argc, char **argv)
{
    int n,m,st,ed;
    cin>>n>>m>>st>>ed;
    
    fill(G[0],G[0]+maxn*maxn,INF);
    
    for(int i=0;i<m;i++){
        int u,v,w,co;
        cin>>u>>v>>w>>co;
        G[u][v]=w;
        cost[u][v]=co;
    }
    
    Dijkstra(st,n);
    
    DFS(ed);
    
    cout<<d[ed]<<" "<<c[ed]<<endl;

    return 0;
}

