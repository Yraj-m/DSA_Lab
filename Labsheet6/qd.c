#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    int max = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>max)
            max = arr[i];
    }
     int *hash = (int*)malloc(max*sizeof(int));

    int flag = 0;
    
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;

        if(hash[arr[flag]]==1)
        {
            printf("%d ",arr[flag]);
        }
        else
        {
            while(hash[arr[flag]]!=1 && flag<i)
            {
                flag++;
            }
            if(flag==i)
            {
                    printf("-1 ");
                    if(flag!=n-1)
                        flag++;
            }
            else
            {
                printf("%d ",arr[flag]);
            }
        }
    }
    free(arr);
    return(0);
}