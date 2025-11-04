#include<stdio.h>
void firstfit(int blocksize,int n,int processsize,int m){
    int allocation[10];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocksize[j]<=processsize[i]){
                allocation[i]=j
                blocksize[j]-=processsize[i];
            }
        }
    }
    printf("Processno\tProcessize\tBlock no");
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("%d\t%d\t%d\t\n",i+1,processsize[i],allocation[i]);
        }
        else
            printf("%d\t%d\tNot allocated\t\n",i+1,processsize[i],allocation[i]);
    }
}
void bestfit(int blocksize,int n,int processsize,int m){
    int allocation[10],bestidx==-1;
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocksize[j]<=processsize[i]){
                if(bestidx==-1||blocksize[j]<blocksize[bestidx])
                    bestidx=j;
            }
        }
    }
    if(bestidx!=-1){
        allocation[i]=bestidx;
        blocksize[bestidx]-=processsize[i];
    }
    printf("Processno\tProcessize\tBlock no");
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("%d\t%d\t%d\t\n",i+1,processsize[i],allocation[i]);
        }
        else
            printf("%d\t%d\tNot allocated\t\n",i+1,processsize[i],allocation[i]);
    }
}

