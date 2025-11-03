#include<stdio.h>
void printallocation(const char *title,int allocation[],int processsize[],int n){
    printf("\n%s Allocation:\n",title);
    printf("Process No\tProcess size\tBlock no\n");
        for(int i=0;i<n;i++){
            if(allocation[i]!=-1)
                printf("%d\t\t%d\t\t%d\n",i+1,processsize[i],allocation[i]+1);
            else
                printf("%d\t\t%d\t\tNot allocated \n",i+1,processsize[i]);
        }
}
void Firstfit(int blocksize[],int m,int processize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
        for(int j=0;j<m;j++){
            if(blocksize[j]>=processize[i]){
                allocation[i]=j;
                blocksize[j]-=processize[i];
                break;
            }
        }
    }
    printallocation("First_Fit",allocation,processize,n);
}
void Bestfit(int blocksize[],int m,int processize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
        int bestidx=-1;
        for(int j=0;j<m;j++){
            if(blocksize[j]>=processize[i]){
                if(bestidx==-1||blocksize[j]<=blocksize[bestidx]){
                    bestidx=j;
                }
            }
        }
        if(bestidx!=-1){
            allocation[i]=bestidx;
            blocksize[bestidx]-=processize[i];
        }
    }
    printallocation("BestFit",allocation,processize,n);
}
void Worstfit(int blocksize[],int m,int processize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
        int wrstidx=-1;
        for(int j=0;j<m;j++){
            if(blocksize[j]>=processize[i]){
                if(wrstidx==-1||blocksize[j]>blocksize[wrstidx]){
                    wrstidx=j;
                }
            }
        }
        if(wrstidx!=-1){
            allocation[i]=wrstidx;
            blocksize[wrstidx]-=processize[i];
        }
    }
    printallocation("Worstfit",allocation,processize,n);
}
int main(){
    int n,m,choice;
    printf("\nEnter the no of processes:");
    scanf("%d",&n);
    int processsize[n];
    printf("Enter the process sizes:");
    for(int i=0;i<n;i++){
        scanf("%d",&processsize[i]);   
     }
    printf("\nEnter the no of mmry blocks:");
    scanf("%d",&m);
    int blocksize[m];
    int original_blocksize[m];
    printf("Enter the block sizes");
    for(int j=0;j<m;j++){
        scanf("%d",&blocksize[j]);
        original_blocksize[j]=blocksize[j];
     }
    printf("Memory allocations supported:\n1)FirstFit\n2)BestFit\n3)Worstfit\n");
    printf("Enter your choice number:");
    scanf("%d",&choice);
    switch(choice){
        case 1:Firstfit(blocksize,m,processsize,n);
               break;
        case 2:Bestfit(blocksize,m,processsize,n);
               break;
        case 3:Worstfit(blocksize,m,processsize,n);
               break;
        default:printf("Invalid ah");
    }
    return 0;

    
}