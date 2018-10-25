#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
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
int d[maxn],num[maxn];
bool inq[maxn];

bool SPFA(int s){
    memset(inq,false,sizeof(inq));
    memset(num,0,sizeof(num));
    fill(d,d+maxn,INF);
    queue<int> Q;
    Q.push(s);
    inq[s]=true;
    num[s]++;
    d[s]=0;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        inq[u]=false;
        
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;
            int dis=Adj[u][j].dis;
            if(d[u]+dis<d[v]){
                d[v]=d[u]+dis;
                if(!inq[v]){
                    Q.push(v);
                    inq[v]=true;
                    num[v]++;
                    if(num[v]>=n) return false;
                }
            }
        }
    }
    
    return true;
}

int main(int argc, char **argv)
{
    int s;
    cin>>n>>m>>s;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        Adj[u].push_back(node(v,w));
    }
    
    SPFA(s);
    
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
    
    cout<<endl;

    return 0;
}

