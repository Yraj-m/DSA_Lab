#include<iostream>

using namespace std;


void gst(int arr[], int curr, int n, int &sum,int ans[])
{
    int left = (2*curr + 1);
    int right = (2*curr + 2);

    if(arr[curr]==-1)
    {
        ans[curr] = -1;
        return;
    }
    if(curr>=n)
    {
        return;
    }

    gst(arr,right,n,sum,ans);
    ans[curr] = arr[curr] + sum;
    sum = ans[curr];
    gst(arr,left,n,sum,ans);
}

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    int *ans = new int[n]();

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum = 0;

    gst(arr,0,n,sum,ans);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i];
    }
    return(0);
}