#include<stdio.h>
#include<stdlib.h>

int main(){

    long int n,k, *arr,temp,i;
    int sub=1;


    scanf("%li",&k);
    scanf("%li",&n);

    long int comp = (k+1)/2;

    arr = (long int*)malloc(n * sizeof(long int*));

    for(i=0;i<n;i++){
        scanf("%li",&arr[i]);
    }

    while(sub){
        sub=0;
        for(i=0;i<n-1;i++){
            if(arr[i]>=comp && arr[i+1]<=comp)
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