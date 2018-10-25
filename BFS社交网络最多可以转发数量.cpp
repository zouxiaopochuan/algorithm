#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn=1010;

struct Node{
    int id;
    int layer;
};

vector<Node> Adj[maxn];
bool inq[maxn]={false};


int BFS(int n,int L){
    int numForward=0;
    queue<Node> q;
    Node start;
    start.id=n;
    start.layer=0;
    q.push(start);
    inq[start.id]=true;
    while(!q.empty()){
        Node temp=q.front();
        q.pop();
        for(int i=0;i<Adj[temp.id].size();i++){
            Node next=Adj[temp.id][i];
            next.layer=temp.layer+1;
            if(inq[next.id]==false&&next.layer<=L){
                q.push(next);
                inq[next.id]=true;
                numForward++;
             
            }
        }
    }
    
    return numForward;
}


int main(int argc, char **argv)
{
    Node user;
    int n,L,numFollow,idFollow;
    cin>>n>>L;
    
    for(int i=1;i<=n;i++){
        user.id=i;
        cin>>numFollow;
        for(int j=0;j<numFollow;j++){
            cin>>idFollow;
            Adj[idFollow].push_back(user);
        }
    }
    
    int numQuery,s;
    cin>>numQuery;
    for(int i=0;i<numQuery;i++){
        fill(inq,inq+maxn,false);
        cin>>s;
        int numForward=BFS(s,L);
        
        cout<<numForward<<endl;
    }
    return 0;
}

