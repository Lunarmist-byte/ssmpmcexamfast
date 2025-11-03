#include<stdio.h>
void main(){
    int rs[25],m[10],n,flag[25],f,pf=0,k=0,found;
    printf("Enter the length of reference string:");
    scanf("%d",&n);
    printf("Enter the string:");
    for(int i=0;i<n;i++){
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    printf("No of frames:");
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        m[i]=-1;
    }
    printf("\nFIFO\n");
    for(int i=0;i<n;i++){
        found=0;
        for(int j=0;j<f;j++){
            if(m[j]==rs[i]){
            found=1;
            break;
        }
    }
    if(found==0){
        m[k]=rs[i];
        k=(k+1)%f;
        pf++;
    }
    for(int j=0;j<f;j++){
        if(m[j]!=-1){
            printf("%d\t",m[j]);
        }
        else{
            printf("-\t");
        }
    }
        if(found==0){
            printf("PF--%d",pf);
            printf("\n");
        }
    }
    printf("Total no of page faults:%d",pf);


}
