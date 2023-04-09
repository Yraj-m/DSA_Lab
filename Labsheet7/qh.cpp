#include<iostream>

using namespace std;


void beautBST(int arr[], int curr, int n, int lb, int ub)
{
    int left = (2*curr + 1);
    int right = (2*curr + 2);

    if(curr>=n || arr[curr]==-1)
    {
        return;
    }


    if(arr[curr]>=lb)
        beautBST(arr,left,n,lb,ub);
    if(arr[curr]<=ub)
        beautBST(arr,right,n,lb,ub);
    if( arr[curr] >= lb && arr[curr] <=ub)
    {
        cout<<arr[curr]<<" ";
    }
    
}

int main()
{
    int n,lb,ub;
    cin>>n>>lb>>ub;

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    beautBST(arr,0,n,lb,ub);

    return(0);
}