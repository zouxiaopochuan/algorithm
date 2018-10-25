#include <iostream>
#include <algorithm>

using namespace std;

const int maxv=110;
const int maxe=10010;

struct edge{
    int u,v;
    int cost;
}E[maxe];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int father[maxv];
int findFather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    }
    
    while(a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    
    return x;
}

int kruskal(int n,int m){
    int ans=0,Num_Edge=0;
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    
    sort(E,E+m,cmp);
    for(int i=0;i<m;i++){
        int faU=findFather(E[i].u);
        int faV=findFather(E[i].v);
        if(faU!=faV){
            father[faU]=faV;
            ans+=E[i].cost;
            Num_Edge++;
            if(Num_Edge==n-1) break;
        }
    }
    
    if(Num_Edge!=n-1) return -1;
    return ans;
}

int main(int argc, char **argv)
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>E[i].u>>E[i].v>>E[i].cost;
    }
    
    int ans=kruskal(n,m);
    
    cout<<ans<<endl;
 
    return 0;
}

