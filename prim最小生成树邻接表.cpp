#include <iostream>
#include <vector>

using namespace std;

struct node{
    int v;
    int dis;
    node(int _v,int _dis):v(_v),dis(_dis){}
};

const int maxn=100;
const int INF=1000000000;

vector<node> Adj[maxn];
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
        
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;
            int dis=Adj[u][j].dis;
            if(vis[j]==false&&dis<d[v]){
                d[v]=dis;
            }
        }
    }
    return ans;
}


int main(int argc, char **argv)
{
    int n,m;
    cin>>n>>m;
    
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        Adj[u].push_back(node(v,w));
        Adj[v].push_back(node(u,w));
    }
    
    int ans=prim(n);
    
    cout<<ans<<endl;

 
    return 0;
}

