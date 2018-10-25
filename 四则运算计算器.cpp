#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>


using namespace std;

struct node{
    double num;
    char op;
    bool flag;
};

queue<node> qu;
stack<node> st;
map<char,int> mp;

void changeStr(string str){
    node temp;
    for(int i=0;i<str.length();){
        if(str[i]>='0'&&str[i]<='9'){
            temp.flag=true;
            temp.num=str[i]-'0';
            i++;
            while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
                temp.num=temp.num*10+str[i]-'0';
                i++;
            }
            qu.push(temp);
        }else if(str[i]=='('){
            temp.flag=false;
            temp.op='(';
            i++;
            st.push(temp);
        }else if(str[i]==')'){
            while(!st.empty()&&st.top().op!='('){
                qu.push(st.top());
                st.pop();
            }
            st.pop();
            i++;
        }else{
            temp.flag=false;
            temp.op=str[i];
            i++;
            while(!st.empty()&&st.top().op!='('&&mp[st.top().op]>=mp[temp.op]){
                qu.push(st.top());
                st.pop();
            }
            st.push(temp);
        }
    }
    
    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
}

double cal(string str){
    changeStr(str);
    node temp;
    while(!qu.empty()){
        temp=qu.front();
        qu.pop();
        if(temp.flag)
            st.push(temp);
        else{
            node temp1=st.top();
            st.pop();
            node temp2=st.top();
            st.pop();
            switch(temp.op){
                case '-':temp1.num=temp2.num-temp1.num;
                    break;
                case '+':temp1.num=temp2.num+temp1.num;
                    break;
                case '*':temp1.num=temp2.num*temp1.num;
                    break;
                case '/':temp1.num=temp2.num/temp1.num;
                    break;
                default:
                    cout<<"输入有误！！"<<endl;
            }
            st.push(temp1);
        }
    }
    
    temp=st.top();
    st.pop();
    return temp.num;
}

int main(int argc, char **argv)
{
    mp['-']=mp['+']=1;
    mp['*']=mp['/']=2;
    
    string str;
    while(cin>>str){
        double num=cal(str);
        
        cout<<num<<endl;
    }
    
    return 0;
}

