#include <iostream>

using namespace std;

void insertSort(int A[] ,int left,int right){
    for(int i=left+1;i<=right;i++){
        int j=i-1;
        int temp=A[i];
        while(j>=left&&temp<A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
    }
    
}

void selectSort(int A[], int left,int right){
    for(int i=left; i<=right; i++){
        int k=i;
        for(int j=i;j<=right;j++){
           if(A[k]>A[j]){
                k=j;
            }
        }
        
        int temp=A[i];
        A[i]=A[k];
        A[k]=temp;
    }
}

const int maxn=100;

void merge(int A[],int L1,int R1,int L2,int R2){
    int temp[maxn],index=0;
    int i=L1,j=L2;
    while(i<=R1&&j<=R2){
        if(A[i]<A[j])
            temp[index++]=A[i++];        
        else
            temp[index++]=A[j++];
    }
    
    while(i<=R1)
        temp[index++]=A[i++];
    while(j<R2)
        temp[index++]=A[j++];
        
    for(i=0;i<index;i++){
        A[L1+i]=temp[i];
    }
}

void mergeSort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);
    }
}


int partition(int A[],int left,int right){
    int temp=A[left];
    while(left<right){
        while(left<right&&A[right]>temp)right--;
        A[left]=A[right];
        while(left<right&&A[left]<=temp)left++;
        A[right]=A[left];
    }
    A[left]=temp;
    
    return left;
}

void quickSort(int A[],int left,int right){
    if(left<right){
        int pos=partition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}