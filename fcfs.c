#include<stdio.h>
#include<stdlib.h>

int main()
{
    int pn,pno[20],at[20],bt[20],i,tat[20],com[20],wt[20],temp,j;
    float avg=0,avg2=0,avgtat=0,avgwt=0;
    printf("Enter the number of process for FCFS SCHEDULING\n");
    scanf("%d",&pn);
    printf("Enter the process 1 by 1\n");
    for(i=0;i<pn;i++)
        scanf("%d",&pno[i]);
    printf("Enter the Arrival time of the process\n");
    for(i=0;i<pn;i++)
        scanf("%d",&at[i]);
    printf("Enter the Burst time of the process\n");
    for(i=0;i<pn;i++)
        scanf("%d",&bt[i]);

    for(i=0;i<pn;i++)
    {
        for(j=i+1;j<pn;j++)
        {
            if(at[i]>at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=pno[i];
                pno[i]=pno[j];
                pno[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

            }
        }
    }								//sorting according to arrival time

    com[0]=bt[0]+at[0];
    tat[0]=bt[0];
    wt[0]=0;
    for(i=1;i<pn;i++)
    {
        if(com[i-1]>=at[i])
        {
            com[i]=abs(com[i-1]+bt[i]);
        }
        else
            com[i]=abs(at[i]+bt[i]);             //completion time
    }

    for(i=0;i<pn;i++)
        tat[i]=abs(com[i]-at[i]);		//turn around time


    for(i=0;i<pn;i++)
        wt[i]=abs(tat[i]-bt[i]);		//waiting time

    for(i=0;i<pn;i++)
        avg=avg+tat[i];

    avgtat=avg/pn;					//average TAT

    for(i=0;i<pn;i++)
        avg2=avg2+wt[i];

    avgwt=avg2/pn;					//average WT


    printf("Process name\t Arrival time\t Burst time\t Completion time\t Turn around time\t Waiting time\t\n");
    for(i=0;i<pn;i++)
    {
        printf("P%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n",pno[i],at[i],bt[i],com[i],tat[i],wt[i]);
    }

    printf("Average Turn Around Time= %0.2f\nAverage Waiting Time= %0.2f\n",avgtat,avgwt);

}
