#include<iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int start = 0;
    int end = 0;
    int num = arr[0];
    int ans;

    while(start < n && end < n)
    {
        if(num<=k)
        {   
            end++;
            if(start<end)
            {
                ans += end-start;
            }
            if(end<n)
            {
                num += arr[end];
            }
        }
        else
        {
            num -= arr[start];
            start++;

        }
    }
    cout<<ans<<endl;
    return(0);


}