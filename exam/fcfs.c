#include<stdio.h>
void main(){
    int wt[10],tat[10],bt[10],n,p[10];
    float twt,ttat,avgtwt,avgtat;
    printf("Enter no of proccesses:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter BT of pid%d",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    wt[0]=0;
    tat[0]=bt[0];
    ttat+=tat[0];
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    printf("\nPid\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t\n",p[i],bt[i],wt[i],tat[i]);
        twt+=wt[i];
        ttat+=tat[i];
    }
    avgtwt=twt/n,avgtat=ttat/n;
    printf("Avg waiting time%.2f\n",avgtwt);
    printf("Avg TAT:%.2f",avgtat);
}