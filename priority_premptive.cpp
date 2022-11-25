#include<bits/stdc++.h>
using namespace std;
#define n 7
struct process
{
    int id;
    int at;
    int st;
    int bt;
    int ct;
    int tat;
    int pr;
    int rt;
    int wt;
};
vector<int> available(process *pt,int gt)
{
    vector<int> av;
    for(int i=0;i<n;i++)
    {
        if(pt[i].at<=gt&&pt[i].bt!=0)
        av.push_back(pt[i].id);
    }
    return av;
}
bool iscomplete(process *pt)
{
    for(int i=0;i<n;i++)
    {
        if(pt[i].bt!=0)
        return false;
    }
    return true;
}
int main()
{
    process p[n];
    // for(int i=0;i<n;i++)
    // {
    //      cout<<"\nEnter the process id";
    //      cin>>p[i].id;
    //      cout<<"\nEnter the process at";
    //      cin>>p[i].at;
    //      cout<<"\nEnter the process bt";
    //      cin>>p[i].bt;     
    // }
    p[0].id=0;p[1].id=1;p[2].id=2;p[3].id=3;p[4].id=4;p[5].id=5;p[6].id=6;
    p[0].at=0;p[1].at=1;p[2].at=2;p[3].at=3;p[4].at=4;p[5].at=5;p[6].at=6;
    p[0].bt=4;p[1].bt=2;p[2].bt=3;p[3].bt=5;p[4].bt=1;p[5].bt=4;p[6].bt=6;
    p[0].pr=2;p[1].pr=4;p[2].pr=6;p[3].pr=10;p[4].pr=8;p[5].pr=12;p[6].pr=9;
    for(int i=0;i<n;i++)
    p[i].st=-1;   
    
    int gt=0;
    vector<int> av;
    vector<int> btt;
    for(int i=0;i<n;i++)
    {
        btt.push_back(p[i].bt);
    }
    while(!iscomplete(p))
    {
       
        av=available(p,gt);
        if(av.size()==0)
        {
            gt++;
            continue;
        }
        int max=INT_MIN;
        int st;
        for(auto j:av)
        {
            cout<<gt<<" "<<j<<endl;
            if(p[j].pr>max){
            max=p[j].pr;
            st=p[j].id;
            }
            else if(p[j].pr==max)
            {
                if(p[j].at<p[st].at)
                st=p[j].id;
            }

        }
        cout<<endl;
        //cout<<p[st].id+1<<" ";
        if(p[st].st==-1)
        p[st].st=gt;
    
        p[st].bt--;
        p[st].ct=gt+1;
        gt++;
        cout<<gt<<endl;
    }
    for(int i=0;i<n;i++)
    {
        p[i].bt=btt[i];
    }
    for(int i=0;i<n;i++)
    {
        p[i].rt=p[i].st-p[i].at;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    cout<<"id\tat\tbt\tpr\tst\tct\trt\ttat\twt"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].pr<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].rt<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }

}
