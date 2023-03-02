#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int findGcd(long int b, long int k)
{
    long int sm = k<b?k:b;
    long int la = k<b?b:k;
    if(b==0)
        return k;
    return (findGcd(la%sm,sm));
}
int main()
{
    long int n,m;
    scanf("%ld %ld",&n,&m);
    long int root = sqrt(n);
    long int i;
    long int ans=1;
    for(i=root;i>=1;i--)
    {
        if(n%i==0)
        {
                if(findGcd(i,m)==1)
                {
                    if(ans<i)
                    ans=i;
                }
                if(findGcd(n/i,m)==1)
                {
                    if(ans<n/i)
                        ans=n/i;
                }
            
        }
    }
    printf("%ld",ans);
    return(0);
}