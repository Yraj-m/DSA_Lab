#include<stdio.h>
#include<stdlib.h>
#include "merge.c"



// void mergeArray(int arr[],int left,int right,int mid)
// {
//     int n1 = mid-left+1;
//     int n2 = right-mid;
//     int n = left;
//     int p1 = 0;
//     int p2 = 0;
//     int *arr1 = (int*)malloc(n1*sizeof(int));
//     int *arr2 = (int*)malloc(n2*sizeof(int));
//     for(int i=0;i<n1;i++)
//     {
//         arr1[i] = arr[left+i];
//     }
//     for(int i=0;i<n2;i++)
//     {
//         arr2[i] = arr[mid+i+1];
//     }
//     while(p1<n1 || p2<n2)
//     {
//         if(p1==n1)
//         {
//             arr[n] = arr2[p2];
//             p2++;
//         }
//         else if(p2==n2)
//         {
//             arr[n] = arr1[p1];
//             p1++;
//         }
//         else if(arr1[p1]<=arr2[p2])
//         {
//             arr[n] = arr1[p1];
//             p1++;
//         }
//         else if(arr1[p1]>arr2[p2])
//         {
//             arr[n] = arr2[p2];
//             p2++;
//         }
//         n++;
//     }

// }

// void mergeSort(int arr[],int left,int right)
// {
//     if(left<right)
//     {
//         int mid = (left + right)/2;
//         mergeSort(arr,left,mid);
//         mergeSort(arr,mid+1,right);
//         mergeArray(arr,left,right,mid);
//     }
// }


int main()
{
    int n;
    long long int sum =0;
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    long long int avg = sum / n;
    int index = n/2;
    if(n%2==0)
    {
        index-=1;
    }

    mergeSort(arr,0,n-1);

    long long int med = arr[index];
    int oper = 0;

    for(int i = 0;i<n;i++)
    {
        oper += abs(arr[i] - med);
    }
    printf("%d",oper);
    free(arr);
    return(0);


}