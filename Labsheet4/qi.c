#include<stdio.h>
#include<stdlib.h>


int findGcd(int a, int b)
{
    int max = a>b?a:b;
    int min = a<b?a:b;
    if(a==0)
        return b;
    return findGcd(max%min,min);

}

int gcdArr(int arr[],int n,int k)
{
    int gcd = -1;
    for(int i = 0;i<n-1;i++)
    {
        if(i == k)
            continue;
        if(gcd==-1)
        {
            gcd = arr[i];
            continue;
        }
        gcd = findGcd(gcd , arr[i]);
    }
    return gcd;
}

int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int min = findGcd(arr[0],arr[1]);
    int index = 0;
    for(int i=1;i<n-1;i++)
    {
        int temp = findGcd(arr[i],arr[i+1]);
        if (temp < min)
        {
            min = temp;
            index = i;
        }
    }

    int temp1 = gcdArr(arr,n,index);
    int temp2 = gcdArr(arr,n,index+1);

    int max_gcd = temp1>temp2?temp1:temp2;

    printf("%d",max_gcd);
    free(arr);
    return(0);


}