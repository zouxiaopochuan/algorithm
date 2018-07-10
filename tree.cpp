#include <cstdio>
#include <iostream>
#include <queue>
#include "tree.h"

using namespace std;

static node* newNode(int v){
    node* new_node=new node;
    new_node->data=v;
    new_node->lchild=new_node->rchild=NULL;
    
    return new_node;
}

void insertNode(node* &root,int x){
    if(root==NULL){
        root=newNode(x);
        return;
    }
    
    if(x<root->data)
        insertNode(root->lchild,x);
    else
        insertNode(root->rchild,x);
}

node* Create(int data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++){
        insertNode(root,data[i]);
    }
    
    return root;
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void midOrder(node* root){
    if(root==NULL)
        return;
    midOrder(root->lchild);
    cout<<root->data;
    midOrder(root->rchild);
}

void postOrder(node* root){
    if(root==NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout<<root->data;
}

void layerOrder(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->data;
        if(temp->lchild!=NULL)
            q.push(temp->lchild);
        if(temp->rchild!=NULL)
            q.push(temp->rchild);
    }
}



















