#include <iostream>
#include <string>

using namespace std;


int swap(char *str,int a,int b){
    char temp=str[a];
    str[a]=str[b];
    str[b]=temp;
    
    return 0;
}

int permutation(char *str,int begin,int num){
    
    if(begin==num){
        cout<<str<<endl;
    }else{
        for(int i=begin;i<num;i++){
            swap(str,i,begin);
            permutation(str,begin+1,num);
            swap(str,i,begin);
        }
    }
    
    return 0;
}


int main(int argc, char **argv)
{
    char str[5];
    
    for(int i=0;i<5;i++){
        cin>>str[i];
    }
    
    permutation(str,0,5);
    
    return 0;
}

