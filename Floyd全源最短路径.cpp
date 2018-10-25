#include <iostream>

using namespace std;

const int maxn=100;
const int INF=1000000000;

int dis[maxn][maxn];

void Floyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
}


int main(int argc, char **argv)
{
    int n,m;
    cin>>n>>m;
    
    fill(dis[0],dis[0]+maxn*maxn,INF);
    
    for(int i=0;i<n;i++) dis[i][i]=0;
    
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        dis[u][v]=w;
    }
    
    Floyd(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

