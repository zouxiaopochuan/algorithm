#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    priority_queue<int,vector<int>,greater<int> > q;
    while(cin>>n){
        int a;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a;
            q.push(a);
        }
        
        while(q.size()>1){
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            ans+=x+y;
            q.push(x+y);
        }
        
        cout<<ans<<endl;
        
    }

    return 0;
}

