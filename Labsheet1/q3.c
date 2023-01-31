#include<stdio.h>
#include<stdlib.h>

long int ind=0;

int subSum( long int *arr,long int *ans,int num, int sum)
{
    if(sum==0){
        // ans[ind]=num;
        // ind++;
        return 1;
    }
    if(num==0)
        return 0;
    
    if(arr[num-1]>sum){
        return(subSum(arr,ans,num-1,sum));
    }
    else{
        if(subSum(arr,ans,num-1,sum-arr[num-1])==1){
            ans[ind]=num-1;
            ind++;
            return 1;
        }
        else if(subSum(arr,ans,num-1,sum)==1){
            return 1;
        }
        else
            return 0;
    }

}

int main(){
    long int n,s,i,j,*arr,*ans;
    
    scanf("%li",&n);

    arr = (long int*)malloc(n * sizeof(long int*));

    for(i=0;i<n;i++){
        scanf("%li",&arr[i]);
    }

    scanf("%li",&s);

    ans = (long int*)malloc(n * sizeof(long int*));

    for(i=0;i<n;i++){
        ans[i]=-1;
    }

    int res = subSum(arr,ans,n,s);

    if(res==1){
        printf("POSSIBLE\n");
        i=0;
        while(ans[i]!=-1 && i<n ){
            printf("%li ",ans[i]);
            i++;
        }
    }
    else
        printf("NOT POSSIBLE\n");

    free(arr);
    free(ans);

    return(0);

}