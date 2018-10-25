#include <iostream>
#include <queue>

using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

const int maxn=50;

int pre[maxn],mid[maxn],post[maxn];

node* create(int preL,int preR,int midL,int midR){
    
    if(preL>preR) return NULL;
    
    node* root =new node;
    root->data=pre[preL];
    
    int i;
    for(i=midL;i<=midR;i++){
        if(mid[i]==pre[preL]) break;
    }
    
    int numLeft=i-midL;
    
    root->lchild=create(preL+1,preL+numLeft,midL,i-1);
    root->rchild=create(preL+numLeft+1,preR,i+1,midR);
    
    return root;
}

void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();7
        q.pop();
        cout<<temp->data<<" ";
        if(temp->lchild!=NULL) q.push(temp->lchild);
        if(temp->rchild!=NULL) q.push(temp->rchild);
    }
    cout<<endl;
}


int main(int argc, char **argv)
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>mid[i];
    }
    
    node* root=create(0,n-1,0,n-1);
    
    BFS(root);

    return 0;
}

