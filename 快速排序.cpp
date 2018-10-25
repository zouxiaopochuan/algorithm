#include <iostream>

const int maxn=1024;

using namespace std;


int Partition(int *A,int left,int right){
    int temp=A[left];
    while(left<right){
        while(left<right&&A[right]>=temp) right--;
        A[left]=A[right];
        while(left<right&&A[left]<=temp) left++;
        A[right]=A[left];
    }
    
    A[left]=temp;
    
    return left;
}

int quick_sort(int *A,int left,int right){
    if(left<right){
        int pos=Partition(A,left,right);
        quick_sort(A,left,pos-1);
        quick_sort(A,pos+1,right);
    }
    
    return 0;
}

int main(int argc, char **argv)
{
    
    int A[20]={10,1,3,0,100,-10,20,50,1000,200};
    
   
    quick_sort(A,0,9);
    
    for(int i=0;i<=9;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}

