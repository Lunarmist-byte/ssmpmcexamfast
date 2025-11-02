#include<stdio.h>
struct process{
    int pid;
    int bt;
    int pri;
    int wt;
    int tat;
};
int main(){
    int n;
    printf("Enter no of processes:");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter the BT and priority of pid%d:",p[i].pid);
        scanf("%d%d",&p[i].bt,&p[i].pri);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].pri<p[i].pri+1){
            struct process temp=p[i];
            p[i]=p[j];
            p[j]=temp;
            }
        }
    }
    p[0].wt=0;
    p[0].tat=p[0].bt;
    for(int i=1;i<n;i++){
        p[i].wt=p[i-1].wt+p[i-1].bt;
        p[i].tat=p[i].bt+p[i].wt;
    }
    float twt,ttat;
    printf("%8s%5s%5s%5s%5s\n","Pno","Priority","BT","WT","TAT");
    for(int i=0;i<n;i++){
        printf("\n%8d%5d%5d%5d\n",p[i].pid,p[i].pri,p[i].bt,p[i].wt,p[i].tat);
        twt+=p[i].wt;
        ttat+=p[i].tat;
    }
    printf("Avg TAT:%.2f",ttat/n);
    printf("Avg WT:%.2f",twt/n);
    }