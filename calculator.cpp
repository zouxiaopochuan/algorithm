#include <cstdio>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void printq();

struct Node{
    double number;
    char op;
    bool flag;
    };    
    
stack<Node> s;
queue<Node> q;
map<char,int> op;


void change(string mid_str){
    Node temp;
    for(int i=0;i<mid_str.length();){
        if(mid_str[i]<='9' && mid_str[i]>='0'){
            temp.flag=true;
            temp.number=mid_str[i++]-'0';
            while(i<mid_str.length()&&mid_str[i]>='0'&&mid_str[i]<='9'){
                temp.number=temp.number*10+(mid_str[i]-'0');
                i++;
            }
            q.push(temp);
        }else if(mid_str[i]=='('){
            temp.flag=false;
            temp.op=mid_str[i];
            s.push(temp);
            i++;
        }else if(mid_str[i]==')'){
            while(!s.empty()){
                temp=s.top();
                s.pop();
                cout<<"temp.op:";
                cout<<temp.op<<endl;
                if(temp.op=='(')break;
                q.push(temp);
            }
            i++;
        }else{
            temp.flag=false;
        
            while(!s.empty() && op[mid_str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op=mid_str[i];
            s.push(temp);
            i++;   
        }
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
}


double calculator(){
    Node temp;
    double num1,num2;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp.flag){
            s.push(temp);
            cout<<temp.number<<endl;
        }else{
            cout<<temp.op<<endl;
            num2=s.top().number;
            s.pop();
            num1=s.top().number;
            s.pop();
            if(temp.op=='*') temp.number=num1*num2;
            else if(temp.op=='/') temp.number=num1/num2;
            else if(temp.op=='+') temp.number=num1+num2;
            else if(temp.op=='-') temp.number=num1-num2;
            
            temp.flag=true;
            s.push(temp);
            
        } 
       
    }
    
    return s.top().number;
}

int main(int argc, char **argv)
{
    op['+']=op['-']=1;
    op['*']=op['/']=2;
    string str;
    while(getline(cin,str),str!="0"){
        for(string::iterator it=str.end();it!=str.begin();it--){
            if(*it == ' ') str.erase(it);
        }
        
        while(!s.empty()) s.pop();
        
        change(str);
        
        printf("%.2f\n",calculator());
    }

	return 0;
}