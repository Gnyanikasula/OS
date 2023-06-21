#include<bits/stdc++.h>
using namespace std;
int main(){
    int p;
    cout<<"Enter the number of processes:-";
    cin>>p;
    int r;
    cout<<"Enter the number of resources:-";
    cin>>r;
    int alloc[p][r];
    int maxx[p][r];
    cout<<"Enter the allocation matrix"<<endl;;
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"Enter the maximum matrix"<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cin>>maxx[i][j];
        }
    }
    int need[p][r];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++)
            need[i][j]=maxx[i][j]-alloc[i][j];
    }
    int avail[r];
    cout<<"Enter the available matrix:-"<<endl;
    for(int i=0;i<r;i++)
        cin>>avail[i];
    bool done[p];
    memset(done,false,p);
    int nop=0;
    vector<int> sequence;
    while(nop!=p){
        int x=0;
        bool flag=false;
            for(int i=0;i<p;i++){
                if(!done[i]){
                    bool found=true;
                        for(int j=0;j<r;j++){
                            if(avail[j]<need[i][j]){
                                found=false;
                                break;
                            }
                        }
                    if(found){
                        x=i;
                        flag=true;
                        break;
                    }
                }
            }
        if(!flag){
            cout<<"N0 safe sequence"<<endl;
            break;
        }
        else{
            nop++;
            sequence.push_back(x);
            for(int i=0;i<r;i++)
                avail[i]+=alloc[x][i];
            done[x]=true;
        }
    }
    if(nop!=p)
        cout<<"Deadlock"<<endl;
    else{
        cout<<"Safe Sequence is:-";
        for(auto x:sequence)
            cout<<x<<" ";
    }
    return 0;
}
