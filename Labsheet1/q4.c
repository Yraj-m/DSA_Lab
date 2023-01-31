#include<stdio.h>
#include<stdlib.h>

int main(){

    long int n, *arr,temp;
    int i,sub=1,check=10;

    scanf("%li",&n);

    arr = (long int*)malloc(n * sizeof(long int*));

    for(i=0;i<n;i++){
        scanf("%li",&arr[i]);
    }

    while(sub){
        sub=0;
        for(i=0;i<n-1;i++){
            if(arr[i]>0 && arr[i+1]<0)
            {
                temp=arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sub=1;
            }
        }
    }


    for(i=0;i<n;i++){
        printf("%li ",arr[i]);
    }

    free(arr);

    return(0);

}