#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int digit_num[8]={1,2,3,4,5,6,7,8};

int count=0;

int swap(int *digit,int a,int b){
    int temp=digit[a];
    digit[a]=digit[b];
    digit[b]=temp;
    
    return 0;
}

int permutation(int *digit,int begin,int num){
    
    if(begin==num){
        bool flag = true;
        for(int i=0;i<=num;i++){
            for(int j=i+1;j<=num;j++){
                if(abs(i-j)==abs(digit[i]-digit[j]))
                    flag=false;
            }
        }
        if(flag) count++;
        
    }else
        for(int i=begin;i<=num;i++){
            swap(digit,i,begin);
            permutation(digit,begin+1,num);
            swap(digit,i,begin);
        }
    
    return 0;
}

int main(int argc, char **argv)
{
    permutation(digit_num,0,7);
    
    cout<<count<<endl;
    
    return 0;
}

