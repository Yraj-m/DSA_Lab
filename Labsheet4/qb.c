#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int lo = 0;
    int hi = n;
    int found ;
    int temp,mid;
    while(lo<=hi)
    {
        mid = (lo+hi)/2;
        temp=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]-mid>=0)
                temp++;
        }
        if(temp==mid)
        {
            found = mid;
            lo = mid+1;
        }
        else if(temp<mid)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    printf("%d",found);
    free(arr);
    return(0);
}