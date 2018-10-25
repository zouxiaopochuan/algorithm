#include <iostream>
#include <queue>

using namespace std;

const int maxn=100;

struct node{
    int x;
    int y;
    int step;
} Node;

int n,m;//矩阵的大小n*m
char matrix[maxn][maxn];
bool inq[maxn][maxn];

int X[4]={1,-1,0,0};
int Y[4]={0,0,1,-1};

queue<node> Q;

bool judge(int x,int y){
    if(x>n||x<0||y>m||y<0) return false;
    if(matrix[x][y]=='*'||inq[x][y]==true) return false;
    
    return true;
}

int BFS(int x,int y){
    Node.x=x;
    Node.y=y;
    Node.step=0;
    Q.push(Node);
    inq[x][y]==true;
    while(!Q.empty()){
        node temp=Q.front();
        Q.pop();
        if(matrix[temp.x][temp.y]=='T')
            return temp.step;
        for(int i=0;i<4;i++){
            int newX=temp.x+X[i];
            int newY=temp.y+Y[i];
            if(judge(newX,newY)){
                Node.x=newX;
                Node.y=newY;
                Node.step=temp.step+1;
                Q.push(Node);
                inq[newX][newY]=true;
            }
        }
    }
    
    return -1;
    
}
    

int main(int argc, char **argv)
{
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    
    int startX,startY;
    cin>>startX>>startY;
    
    int step=BFS(startX,startY);
    cout<<step<<endl;
    

    return 0;
}

