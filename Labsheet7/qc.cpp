#include<iostream>

using namespace std;

void freedom(int arr[], int curr, int n, int x, int &count,int ans[])
{
    int left = (2*curr + 1);
    int right = (2*curr + 2);

    if(arr[curr]==-1)
    {
        return;
    }

    if(curr == 0)
    {
        ans[0] = arr[0];
    }
    else
    {
        int parent = (curr-1)/2;
        ans[curr] = ans[parent] + arr[curr];
    }

    if((left >= n) || (arr[left]==-1 && arr[right]==-1))
    {
        if(ans[curr] == x)
            count++;
        return;
    }
    else
    {
        freedom(arr,left,n,x,count,ans);
        if(right<n);
        {
            freedom(arr,right,n,x,count,ans);
        }
    }
}

int main()
{
    int n,x;
    cin>>n>>x;

    int *arr = new int[n];
    int *ans = new int[n]();

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int count = 0;

    freedom(arr,0,n,x,count,ans);

    cout<<count<<endl;
}