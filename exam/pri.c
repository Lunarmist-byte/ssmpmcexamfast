#include<stdio.h>
struct process{
    int pid;
    int bt;
    int pri;
    int tat;
    int wt;
}p[12];
int main(){
    int n;
    float twt,ttat;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the BT and Priority of pid:%d:",p[i].pid);
        scanf("%d%d",&p[i].bt,&p[i].pri);
        p[i].pid=i+1;
    }
    printf("/nPriority");
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[j].pri<p[i].pri){
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

     printf("\nPid\tBT\tPRI\ttWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].bt,p[i].pri,p[i].wt,p[i].tat);
        twt+=p[i].wt;
        ttat+=p[i].tat;
    }
    float avgtwt=twt/n,avgtat=ttat/n;
    printf("Avg waiting time%.2f\n",avgtwt);
    printf("Avg TAT:%.2f",avgtat);
}
