#include <iostream>

const int maxn=1024;

using namespace std;

int merge(int *A,int left1,int right1,int left2,int right2){
    int i=left1,j=left2,index=0;
    int temp[100];
    while(i<=right1&&j<=right2){
        if(A[i]<=A[j]) temp[index++]=A[i++];
        else temp[index++]=A[j++];
    }
    
    while(i<=right1) temp[index++]=A[i++];
    while(j<=right2) temp[index++]=A[j++];
    
    for(int i=0;i<index;i++){
        A[left1+i]=temp[i];
    }
    
    return index;
}

int mergesort(int *A,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
    
    return 0;
}



int main(int argc, char **argv)
{
    
    int A[20]={10,1,3,0,100,-10,20,50,1000,200};
    
    mergesort(A,0,9);
    
    for(int i=0;i<=9;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}

