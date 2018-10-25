#include <iostream>

using namespace std;

const int maxn=100;

int father[maxn];

void init(int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
}

int findFather(int x){
    while(father[x]!=x){
        x=father[x];
    }
    return x;
}

void Union(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb)  father[fa]=fb;
}

int main(int argc, char **argv)
{
    int n,m;
    while(cin>>n>>m){
        int ans=0;
        init(n);
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            father[a]=b;
        }
        
        for(int i=1;i<=n;i++){
            if(i==father[i])
                ans++;
        }
        
        cout<<ans<<endl;
    }

    return 0;
}

