#include<stdio.h>
struct process{
    int pid;
    int bt;
    int pri;
    int wt;
    int tat;
    int ct;
    int btl;
    int at;
}p[10];
void main(){
    int n,tq;
    printf("Enter no of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter at,bt of pid%d:",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
        p[i].btl=p[i].bt;
        p[i].wt=p[i].tat=p[i].ct=0;
    }
    printf("Enter the time qunatum");
    scanf("%d",&tq);
    int time=0,done=0;
    while(done<n){
        int flag=0;
        for(int i=0;i<n;i++){
            if(p[i].btl>0 &&p[i].at<=time){
                int exec=p[i].btl<tq?p[i].btl:tq;
                p[i].btl-=exec;
                time+=exec;
                flag=1;
                if(p[i].btl==0){
                    p[i].ct=time;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                    done++;
                }
            }
        }
        if(!flag){
            time++;
        }
         float twt = 0, ttat = 0;
    printf("\n%-5s %-5s %-5s %-5s %-5s %-5s\n", "PID", "AT", "BT", "CT", "TAT", "WT");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-5d %-5d %-5d %-5d %-5d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        twt += p[i].wt;
        ttat += p[i].tat;
    }

    printf("\nAverage Turnaround Time = %.2f", ttat / n);
    printf("\nAverage Waiting Time = %.2f\n", twt / n);
    }
}