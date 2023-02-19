#include<stdio.h>
#include<stdlib.h>

int main()
{
    long int n;
    scanf("%ld",&n);

    long int comp = (n * (n-1))/4;
    long int lo=0;
    long int hi=n-1;
    long int temp = 0;
    long int found = -1;
    long int sum = 0;
    long int val = 2*n -1;

    while(lo<=hi)
    {
        temp = (lo+hi)/2;

        sum = ( (val-temp)*temp) /2;

        if(sum==comp)
        {
            found = temp;
            break;
        }
        else if(sum<comp)
        {
            lo = temp+1;
        }
        else
        {
            hi = temp-1;
            found = temp;
        }
    
    }
    printf("%ld",found);


}