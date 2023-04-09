#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int(n);
    int *ans = new int(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    stack<int> st;
    
    for(int j=0;j<(2*n);j++)
    {
        int x = arr[j%n];
        if(st.empty())
        {
            st.push(j);
            continue;
        }

            if(arr[st.top() % n] < x)
            {
                while(st.empty()==false && arr[st.top() % n] < x )
                {
                    if(st.top()<n)
                    {
                        ans[st.top()] = j - st.top();
                    }
                    st.pop();
                }
                
            }
            st.push(j);
        }        
    
    while(!st.empty())
    {
        if(st.top()<n)
            ans[st.top()] = -1;
        st.pop();
    }
    for(int j=0;j<n;j++)
    {
        cout<<ans[j]<<" ";
    }
    return(0);
}