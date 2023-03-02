#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    int *final = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int digits = 0;
    int div = 1;
    int swap=1;
    while(swap==1)
    {
        swap=0;
        int freq[10] = {0};
        for(int i=0;i<n;i++)
        {
            freq[(arr[i]/div)%10]++;
        }


        for(int i=1;i<10;i++)
        {
            freq[i]+=freq[i-1];
        }

        for(int i=n-1;i>=0;i--)
        {
            final[freq[(arr[i]/div)%10]-1] = arr[i];
            freq[(arr[i]/div)%10]--;
        }

        for(int i=0;i<n;i++)
        {
            printf("%d ",final[i]);
        }

        printf("\n");
        div = div*10;
        for(int i=0;i<n;i++)
        {
            arr[i] = final[i];
            if(arr[i]/div != 0)
                swap=1;
        }
    }
    free(arr);
    free(final);
    return(0);
}