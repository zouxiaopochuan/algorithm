struct node{
    int data;
    int height;
    node* lchild;
    node* rchild;
};

node* Create(int data[],int n);
node* avlCreate(int data[],int n);

void preOrder(node* root);
void midOrder(node* root);
void postOrder(node* root);
void layerOrder(node* root);