#include<iostream>

using namespace std;


int ancestor(int arr[], int curr, int n, int el1, int el2)
{
    int left = (2*curr + 1);
    int right = (2*curr + 2);

    if(curr>=n || arr[curr]==-1)
    {
        return -1;
    }


    int ans_r = ancestor(arr,right,n,el1,el2);
    int ans_l = ancestor(arr,left,n,el1,el2);

    if(ans_r != -1 && ans_l != -1)
    {
        return arr[curr];
    }
    if(arr[curr] == el1)
    {
        return el1;
    }
    if(arr[curr] == el2)
    {
        return el2;
    }
    if(ans_r != -1)
    {
        return ans_r;
    }
    if(ans_l != -1)
    {
        return ans_l;
    }
    return -1;
    
    
}

int main()
{
    int n,el1,el2;
    cin>>n>>el1>>el2;

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int ans = ancestor(arr,0,n,el1,el2);
    cout<<ans<<endl;

    return(0);
}