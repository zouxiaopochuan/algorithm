#include <iostream>
#include <queue>

using namespace std;

const int MAXN=50;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

int pre[MAXN],mirror[MAXN];
int preIndex=0,mirIndex=0;

node* newNode(int x){
    node* Node=new node;
    Node->data=x;
    Node->lchild=NULL;
    Node->rchild=NULL;
    
    return Node;
}

void insert(node* &root,int x){
    if(root==NULL){
        root=newNode(x);
        return;
    }
    if(x>=root->data)
        insert(root->rchild,x);
    else
        insert(root->lchild,x);
        
}

void insertMirror(node* &root,int x){
    if(root==NULL){
        root=newNode(x);
        return;
    }
    
    if(x>=root->data)
        insertMirror(root->lchild,x);
    else
        insertMirror(root->rchild,x);
        
}

node* create(int* data,int n,bool isMirror){
    node* root=NULL;
    for(int i=0;i<n;i++){
        if(!isMirror)
            insert(root,data[i]);
        else
            insertMirror(root,data[i]);
    }
    
    return root;
}

void preOrder(node* root){
    if(root!=NULL){
        pre[preIndex++]=root->data;

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
        cout<<root->data<<" ";
    }
}

void layerOrder(node* root){
    if(root==NULL) return;
    
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


int main(int argc, char **argv)
{
    int n;
    int temp[MAXN];
    while(cin>>n){
        preIndex=0;
        
        for(int i=0;i<n;i++){
            cin>>temp[i];
        }
        
        node* root=create(temp,n,false);
        
        node* rootMirror=create(temp,n,true);
        
        preOrder(root);
        
        int i;
        for(i=0;i<n;i++){
            if(temp[i]!=pre[i])
                break;
        }
        
        if(i==n){
            cout<<"YES"<<endl;
            postOrder(root);
            cout<<endl;
        }else{
            preIndex=0;
        
            preOrder(rootMirror);
            for(i=0;i<n;i++){
                if(temp[i]!=pre[i])
                    break;
            }
            if(i==n){
                cout<<"YES"<<endl;
                postOrder(rootMirror);
                cout<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        
        
    }

    return 0;
}

