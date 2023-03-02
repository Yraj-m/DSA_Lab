#include<stdio.h>
#include<stdlib.h>

struct Element
{
    int val;
    int freq;
};
typedef struct Element ele;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int max = 1e5+10;

    ele *arr = (ele*)malloc((max+1)*sizeof(ele));
    for (int i=0;i<max;i++)
    {
        ele newEle = {i,0};
        arr[i] = newEle;
    }

}