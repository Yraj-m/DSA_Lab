#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    int *ans = new int[n];

    stack<int> st;


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        while((!st.empty()) && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i] = i+1;
        }
        else
        {
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }

    return(0);
}