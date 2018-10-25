#include <iostream>
#include <queue>

using namespace std;

const int MAXN=100;
int num[MAXN];


struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* root=new node;
    root->data=v;
    root->lchild=NULL;
    root->rchild=NULL;
    
    return root;
}

void insert(node* &root,int v){
    if(root==NULL){
        root=newNode(v);
        return;
    }
    if(v<=root->data) insert(root->lchild,v);
    else insert(root->rchild,v);
    
    return;
}

node* creat(int* a,int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insert(root,a[i]);
    }
    
    return root;
}

void preOrder(node* root){
    if(root!=NULL){
        cout<<root->data;
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void midOrder(node* root){
    if(root!=NULL){
        midOrder(root->lchild);
        cout<<root->data;
        midOrder(root->rchild);
    }
}

void postOrder(node* root){
    if(root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        cout<<root->data;
    }
}

void layerOrder(node* root){
    if(root!=NULL){
        queue<node*> Q;
        Q.push(root);
        while(!Q.empty()){
            node* temp=Q.front();
            Q.pop();
            cout<<temp->data;
            if(temp->lchild!=NULL) Q.push(temp->lchild);
            if(temp->rchild!=NULL) Q.push(temp->rchild);
        }
    }
}


int main(int argc, char **argv)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
    node* root=creat(num,n);
    
    preOrder(root);
    cout<<endl;
    midOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    layerOrder(root);
    cout<<endl;


    return 0;
}

