#include <iostream>

using namespace std;


//不重复递增整数数组的二分查找
int binarySearch(int *A,int left,int right,int x){
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if(A[mid]==x) return mid;
        else if(A[mid]<x) left=mid+1;
        else right=mid-1;
    }
    
    return -1;
}

//可能重复的递增序列：第一个大于等于x元素的位置
int lower_bound(int *A,int left,int right,int x){
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(A[mid]>=x) right=mid;
        else left=mid+1;
    }
    if(A[left]<x) return -1;
    return left;
}


//可能重复的递增苏烈：第一个大于x元素的位置
int upper_bound(int *A,int left,int right,int x){
    int mid;
    while(left<right){
        mid=(left+right)/2;
        if(A[mid]<=x) left=mid+1;
        else right=mid;
    }
    
    if(A[right]<x) return -1;
    return right;
}

int main(int argc, char **argv)
{
    int A[10]={0,3,3,3,3,5,6,7,8,9};
    
    int x;
    while(cin>>x)
        cout<<upper_bound(A,0,9,x)<<endl;
   
    return 0;
}

