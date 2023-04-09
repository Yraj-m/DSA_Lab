#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];
    int *right = new int[n];
    int *left = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    stack<int> st;

    for(int i=0; i<n;i++)
    {
        if(st.empty())
        {
            st.push(i);
            continue;
        }
        else
        {
            if ( arr[st.top()] > arr[i] )
            {
                while((!st.empty()) && arr[st.top()] > arr[i])
                {
                    right[st.top()] = i;
                    st.pop(); 
                }
            }
            st.push(i);
        }
    }
    while(!st.empty())
    {
        right[st.top()] = n;
        st.pop();
    }

    for(int i=n-1; i>=0;i--)
    {
        if(st.empty())
        {
            st.push(i);
            continue;
        }
        else
        {
            if ( arr[st.top()] > arr[i] )
            {
                while((!st.empty()) && arr[st.top()] > arr[i])
                {
                    left[st.top()] = i;
                    st.pop(); 
                }
            }
            st.push(i);
        }
    }
    while(!st.empty())
    {
        left[st.top()] = -1;
        st.pop();
    }

    for(int i=0;i<n;i++)
    {
        int temp = (right[i] - left[i] - 1) * arr[i];
        cout<<temp<<" ";
    }
    return(0);



}