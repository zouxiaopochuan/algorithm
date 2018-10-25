#include <iostream>
#include <vector>

using namespace std;

const int maxn=100;
const int INF=1000000000;

struct node{
    int v,dis;
    node(int _v,int _dis):v(_v),dis(_dis){}
};

vector<node> Adj[maxn];
int n,m;
int d[maxn];

bool Bellman(int s){
    fill(d,d+maxn,INF);
    d[s]=0;
    for(int i=0;i<n-1;i++){
        for(int u=0;u<n;u++){
            for(int j=0;j<Adj[u].size();j++){
                int v=Adj[u][j].v;
                int dis=Adj[u][j].dis;
                if(d[u]+dis<d[v]){
                    d[v]=d[u]+dis;
                }
            }
        }
    }
    
    for(int u=0;u<n;u++){
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;
            int dis=Adj[u][j].dis;
            if(d[u]+dis<d[v]){
                return false;
            }
        }
    }
    
    return true;
}


int main(int argc, char **argv)
{
    int st;
    cin>>n>>m>>st;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        Adj[u].push_back(node(v,w));
       // Adj[v].push_back(node(u,w));
        
    }
    
    Bellman(st);
    
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    
    cout<<endl;


    return 0;
}

