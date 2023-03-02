#include<stdio.h>
#include<stdlib.h>


void primeSieve(int arr[],int n)
{
    int i=2;
    while(i*i<=n)
    {
        if(arr[i]==1)
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                arr[j] = 0;
            }
        }
        i++;
    }
}


int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    int *nums = (int*)malloc(q*sizeof(int));
    for(int i=0;i<q;i++)
    {
        scanf("%d",&nums[i]);
    }

    int *arr = (int*)malloc((n+1)*sizeof(int));


    for(int i=0;i<=n;i++)
    {
        arr[i]=1;
    }


    primeSieve(arr,n);

    for (int i=3;i<n;i++)
    {
        arr[i]+=arr[i-1];
    }

    for(int i=0;i<q;i++)
    {
        printf("%d ",arr[nums[i]]);
    }
    free(arr);
    free(nums);
    return(0);


}