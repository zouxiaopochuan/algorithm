#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxn=100;

vector<int> G[maxn];
int inDegree[maxn];

bool topological(int n,int m){
    int num=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0)
                q.push(v);
        }
        G[u].clear();
        num++;
    }
    
    if(num==n) return true;
    return false;
}

void inDegreeCount(int n){
    fill(inDegree,inDegree+maxn,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<G[i].size();j++){
            int v=G[i][j];
            inDegree[v]++;
        }
    }
}


int main(int argc, char **argv)
{
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        G[u].push_back(v);
    }
    
    inDegreeCount(n);
    
    if(topological(n,m))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

