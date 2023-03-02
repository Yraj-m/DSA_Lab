#include<stdio.h>
#include<stdlib.h>

int findZero(int n)
{
    int t = n;
    int count = 0;
    while(t>=5)
    {
        
        count+=(t/5);
        t=t/5;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int *arr = (int*)malloc(n*sizeof(int));
    
    int max = 0;
    long long int pairs=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
            max = arr[i];
    }

     int *count = (int*)calloc((max+1),sizeof(int));

     for(int i=0;i<n;i++)
     {
        count[findZero(arr[i])]++ ;
     }

     for(int i=0;i<=max;i++)
     {
        int f = count[i];
        pairs += (f*(f-1)/2);
     }

    printf("%lld",pairs);
    free(arr);
    free(count);

    return(0);
}