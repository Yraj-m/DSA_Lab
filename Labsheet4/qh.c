#include<stdio.h>
#include<stdlib.h>


long long int findC2(int k)
{
    return ( k * (k-1) / 2 );
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int max = findC2(n-m+1);
    int extra = (n-m)%m ;
    long long int min = extra * (findC2( (n-m)/m + 2 ));
    min+= (m-extra) * (findC2( (n-m)/m + 1 ));

    printf("%lld %lld",min,max);
    return(0);
}