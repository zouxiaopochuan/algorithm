#include <iostream>
#include <queue>

using namespace std;

const int maxn=100;

struct node{
    int x;
    int y;
} Node;

int n,m;//矩阵的大小n*m

int matrix[maxn][maxn];
bool inq[maxn][maxn];
int X[4]={1,-1,0,0};
int Y[4]={0,0,1,-1};

bool judge(int x,int y){
    if(x>n||x<0||y>m||y<0) return false;
    if(matrix[x][y]==0||inq[x][y]==true) return false;
    return true;
}

void BFS(int x,int y){
    queue<node> Q;
    Node.x=x;
    Node.y=y;
    Q.push(Node);
    inq[x][y]=true;
    while(!Q.empty()){
        node temp=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int newX=temp.x+X[i];
            int newY=temp.y+Y[i];
            if(judge(newX,newY)){
                Node.x=newX;
                Node.y=newY;
                Q.push(Node);
                inq[newX][newY]=true;
            }
        }
    }
    
}

int main(int argc, char **argv)
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1&&inq[i][j]==false){
                BFS(i,j);
                ans++;
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}

