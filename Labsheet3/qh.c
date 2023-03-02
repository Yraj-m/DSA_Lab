#include<stdio.h>

int main()
{
    long int n;
    scanf("%ld",&n);

    long int root = -1;
    long int lo = 1;
    long int hi = n/2;
    long int i=0;
    while(lo<=hi)
    {
        i = (lo+hi)/2;
        if(n/i == i)
        {
            root = i;
            break;
        }
        
        else if(n/i > i)
        {
            
            lo = i+1;
            root = i;
        }
        else {
            hi = i-1;
        }
    }

    printf("%ld",root);
    return(0);
}