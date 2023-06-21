#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,at[10],bt[10],ct[10],temp[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the at and bt of the process "<<i+1<<":-";
        cin>>at[i]>>bt[i];
        temp[i]=bt[i];
    }
    int count=0,time=0,smallest;
    for(time=0;count!=n;time++){
        int burst=INT_MAX;
        for(int i=0;i<n;i++){
            if(at[i]<=time and bt[i]>0 and bt[i]<burst){
                burst=bt[i];
                smallest=i;
            }
        }
        bt[smallest]--;
        if(bt[smallest]==0){
            count++;
            int end=time+1;
            ct[smallest]=end;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", at[i], temp[i], ct[i]);
    }
    return 0;
}
