#include<stdio.h>
#include<stdlib.h>

int main(){

    long int m,n, i,j,**arr;
    long int ri,ci,rh,ch,sum=0;


    scanf("%li %li",&m,&n);

    arr = (long int**)malloc(m * sizeof(long int*));
    
    for(i=0;i<m;i++)
        arr[i] = (long int*)malloc(n * sizeof(long int));

    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            scanf("%li",&arr[i][j]);
    }

    scanf("%li %li %li %li",&ri,&ci,&rh,&ch);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            if(j==0){
                if(i)
                    arr[i][j]+=arr[i-1][n-1];
                }
            else
                arr[i][j]+=arr[i][j-1];
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%li ",arr[i][j]);
        printf("\n");
    }

    if(((ri+rh)>m) || ((ci+ch)>m))
        printf("NOT POSSIBLE");
    else{
        for(i=ri;i<(ri+rh);i++){
            for(j=ci;j<(ci+ch);j++)
                sum+=arr[i][j];
        }
        printf("%li",sum);
    }
    for(i=0;i<m;i++)
        free(arr[i]);

    free(arr);

    return(0);
}