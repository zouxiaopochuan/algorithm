#include <iostream>
#include <string>

using namespace std;

const int maxn=100;
int next[maxn];

void getNext(string str){
    int len=str.length();
    next[0]=-1;
    int j=-1;
    
    for(int i=0;i<len;i++){
        while(j!=-1&&str[i]!=str[j+1]){
            j=next[j];
        }
        if(str[i]==str[j+1]){
            j++;
        }
        
        next[i]=j;
    }
    
}

bool KMP(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    getNext(pattern);
    
    int j=-1;
    for(int i=0;i<n;i++){
        while(j!=-1&&text[i]!=pattern[j+1]){
            j=next[j];
        }
        if(text[i]==pattern[j+1]){
            j++;
        }
        
        if(j==m-1) return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    string text,pattern;
    cin>>text>>pattern;
    if(KMP(text,pattern)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}

