#include<stdio.h>
#include<stdlib.h>

int nextIndex(int arr[],int l, int n)
{
    int next = -1;
    int lo = l;
    int hi = n-1;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(arr[l] == arr[mid])
        {
            next = mid;
            lo=mid+1;
        }
        else if(arr[mid] > arr[l])
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return next+1;
}

int main()
{
    int n;
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int i =0;
    int num = 0;
    while(i<n)
    {
        num++;
        i=nextIndex(arr,i,n);

    }
    printf("%d",num);
    free(arr);
    return(0);
}