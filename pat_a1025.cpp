#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student{
    string id;
    int score;
    int location_number;
    int local_rank;
    int total_rank;
}stu[30010];

bool cmp(Student a, Student b){
    if(a.score!=b.score) return a.score>b.score;
    else return a.id.compare(b.id)<0;
}

int main(int argc, char **argv)
{
    int K,N,num=0;
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>stu[num].id>>stu[num].score;
            stu[num].location_number=i+1;
            num++;
        }
        sort(stu+num-N,stu+num,cmp);
        stu[num-N].local_rank=1;
        for(int j=num-N+1;j<num;j++){
            if(stu[j].score==stu[j-1].score)
                stu[j].local_rank=stu[j-1].local_rank;
            else
                stu[j].local_rank=j+1-(num-N);
        }
    }
    
    sort(stu,stu+num,cmp);

    stu[0].total_rank=1;
    cout<<stu[0].id<<" "<<"1 "<<stu[0].location_number<<" "<<stu[0].local_rank<<endl;
    for(int i=1;i<num;i++){
        if(stu[i].score==stu[i-1].score){
            stu[i].total_rank=stu[i-1].total_rank;
            cout<<stu[i].id<<" "<<stu[i].total_rank<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<endl;
        }else{
            stu[i].total_rank=i+1;
            cout<<stu[i].id<<" "<<stu[i].total_rank<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<endl;
            
        }
    }
    
    return 0;
}

