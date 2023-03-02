#include<stdio.h>
#include<stdlib.h>

void mergeArray(int **arr,int left,int right,int mid)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    int n = left;
    int p1 = 0;
    int p2 = 0;
    int **arr1 = (int**)malloc(n1*sizeof(int*));
    int **arr2 = (int**)malloc(n2*sizeof(int*));
    for(int i=0;i<n1;i++)
    {   
        arr1[i] = (int*)malloc(2*sizeof(int));
        arr1[i][0] = arr[left+i][0];
        arr1[i][1] = arr[left+i][1];
    }
    for(int i=0;i<n2;i++)
    {
        arr2[i] = (int*)malloc(2*sizeof(int));
        arr2[i][0] = arr[mid+i+1][0];
        arr2[i][1] = arr[mid+i+1][1];
    }
    while(p1<n1 || p2<n2)
    {
        if(p1==n1)
        {
            arr[n][0] = arr2[p2][0];
            arr[n][1] = arr2[p2][1];
            p2++;
        }
        else if(p2==n2)
        {
            arr[n][0] = arr1[p1][0];
            arr[n][1] = arr1[p1][1];
            p1++;
        }
        else if(arr1[p1]<=arr2[p2])
        {
            arr[n][0] = arr1[p1][0];
            arr[n][1] = arr1[p1][1];
            p1++;
        }
        else if(arr1[p1]>arr2[p2])
        {
            arr[n][0] = arr2[p2][0];
            arr[n][1] = arr2[p2][1];
            p2++;
        }
        n++;
    }
    free(arr1);
    free(arr2);

}

void mergeSort(int **arr,int left,int right)
{
    if(left<right)
    {
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        mergeArray(arr,left,right,mid);
    }
}

int main()
{
    int n,k;
    int MAX = 1e5+10;
    scanf("%d %d",&n,&k);

    int **arr = (int**)calloc(MAX,sizeof(int*));
    for (int i=0;i<MAX;i++)
    {

        arr[i]= (int*)calloc(2,sizeof(int));
        arr[i][0]=i;
        arr[i][1]=0;
    }

    int *nums = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
        arr[nums[i]][1]++;
    }

    mergeSort(arr,1,MAX-1);

    for(int i=0;i<=k+1;i++)
    {
        printf("%d %d\n",arr[i][0],arr[i][1]);
    }

    for(int i=0;i<=k;i++)
    {
        printf("%d ",arr[i][0]);
    }
    free(arr);
    free(nums);
    return(0);
}