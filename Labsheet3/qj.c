#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int* arr = (int*)malloc(n* sizeof(int));

    int sum=0;
    for(int i =0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }

    int val = sum/k;
    if(val==0)
    {
        printf("0");
        return(0);
    }
    int lo=1;
    int hi=val;
    int steps = -1;
    int mid,i;

    while(lo<=hi)
    {
        int temp = 0;
        mid = (lo+hi)/2;

        for(i=0;i<n;i++)
            temp+= (arr[i]/mid);
            
        if(temp >= k)
        {
            steps = mid;
            lo=mid+1;
        }
        else if(temp<k)
        {
            hi = mid-1;
        }
    }
    printf("%d",steps);
    free(arr);
    return(0);
}