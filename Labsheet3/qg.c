#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int left = 0;
    int right = n;
    int found=-1;

    while(left<right)
    {
        int temp = (left+right)/2;
        if(arr[temp]==k)
        {
            found = temp;
            break;
        }
        else if(arr[temp]<k)
        {
            // if(arr[temp+1]>k)
            // {
            //     found=temp;
            //     break;
            // }
            found = temp;
            left = temp+1;
        }
        else
        {
            right=temp-1;
        }
    }
    printf("%d",arr[found]);

    free(arr);
    return(0);


}