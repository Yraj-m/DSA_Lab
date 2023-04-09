#include<iostream>

using namespace std;


int kLarge(int arr[], int curr, int n, int &k)
{
    int left = (2*curr + 1);
    int right = (2*curr + 2);

    if(curr>=n || arr[curr]==-1)
    {
        return -1;
    }

    int val = kLarge(arr,right,n,k);
    if(k==0)
    {
        return val;
    }

    k = k-1;
    if(k==0)
    {
        return arr[curr];
    }

    return kLarge(arr,left,n,k);
    
}

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int ans = kLarge(arr,0,n,k);
    cout<<ans<<endl;

    return(0);
}