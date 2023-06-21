#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,at[10],bt[10],pr[10],ct[10],temp[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the at, bt and pr of the process "<<i+1<<":-";
        cin>>at[i]>>bt[i]>>pr[i];
        temp[i]=bt[i];
    }
    int count=0,time=0;
    for(time=0;count!=n;){
        int priority=INT_MAX;
        int smallest=0;
        for(int j=0;j<n;j++){
            if(bt[j]>0 and pr[j]<priority and at[j]<=time){
                priority=pr[j];
                smallest=j;
            }
        }
        if(priority!=INT_MAX){
            int t=bt[smallest];
            bt[smallest]=0;
            if(bt[smallest]==0){
                count++;
                time+=t;
                int end=time;
                ct[smallest]=end;
            }
        }
        else
            time++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", at[i], temp[i], pr[i],ct[i]);
    }

}
