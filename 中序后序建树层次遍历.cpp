#include <iostream>
#include <queue>

using namespace std;

const int maxn=50;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

int pre[maxn],in[maxn],post[maxn];

int n;//节点的个数

node* create(int inL,int inR,int postL,int postR){
    if(postL>postR) return NULL;
    
    node* root = new node;
    root->data = post[postR];
    int k;
    for(k=inL;k<=inR;k++){
        if(in[k]==post[postR]) break;
    }
    
    int numLeft=k-inL;
    
    root->lchild=create(inL,k-1,postL,postL+numLeft-1);
    root->rchild=create(k+1,inR,postL+numLeft,postR-1);
    
    return root;
}

void BFS(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->lchild!=NULL) q.push(temp->lchild);
        if(temp->rchild!=NULL) q.push(temp->rchild);
    }
    cout<<endl;
}


int main(int argc, char **argv)
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    
    node* root = create(0,n-1,0,n-1);
    
    BFS(root);
    

    return 0;
}

