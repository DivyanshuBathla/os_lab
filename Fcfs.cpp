/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
#define n 5
using namespace std;
struct process
{
    int p;
    int at;
    int bt;
    int st;
    int ct;
    int rt;
    int wt;
    int tat;
};
bool comp(process a,process b )
{
    if(a.at<b.at)
    {
        return true;
    }
    else return false;
}
int main()
{
    struct process p[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the pid=";
        cin>>p[i].p;
        cout<<"\nEnter the at=";
        cin>>p[i].at;
        cout<<"\nEnter the burst time=";
        cin>>p[i].bt;
        
    }
    sort(p,p+n,comp);
    int gt=0;
    int i=0;
    float avg_wt,avg_rt,avg_tat;
    avg_tat=avg_rt=avg_wt=0;
    while(i<n)
    {
        if(p[i].at>gt)
        gt++;
        else
        {
            p[i].st=gt;
            gt+=p[i].bt;
            p[i].ct=gt;
            p[i].rt=p[i].st-p[i].at;
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            avg_wt+=p[i].wt;
            avg_rt+=p[i].rt;
            avg_tat+=p[i].tat;
            i++;
            
        }
    }
    cout<<"pid"<<"\t"<<"at"<<"\t"<<"bt"<<"\t"<<"rt"<<"\t"<<"tat"<<"\t"<<"wt"<<"\t\n";
    for(int i=0;i<n;i++)
    {
        cout<<p[i].p<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].rt<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t\n";
    }
    cout<<"avg_wt"<<avg_wt/n<<endl;
    cout<<"avg_rt"<<avg_rt/n<<endl;
    cout<<"avg_tat"<<avg_tat/n<<endl;
    return 0;
}
