#include<iostream>
#include<map>
#include<set>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;


    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    map<int,int> mp;
    set<int> st;

    for(int i=0;i<m;i++)
    {
        mp[arr[i]]++;
    }
    for(auto it = mp.begin() ; it != mp.end() ; it++)
    {
        if(it->second == k)
        {
            st.insert(it->first);
        }
    }
    if(st.empty())
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<*st.rbegin()<<endl;
        }
    int left = 0;
    int right = m;

    while(right < n)
    {

        if(mp[arr[left]] == 1)
        {
            st.erase(arr[left]);
        }
        if(mp[arr[right]] == 1)
        {
            st.erase(arr[right]);
        }

        mp[arr[right]]++;
        mp[arr[left]]--;

        if(mp[arr[right]] == 1)
        {
            st.insert(arr[right]);
        }
        if(mp[arr[left]] == 1)
        {
            st.insert(arr[left]);
        }
        left++;
        right++;
        if(st.empty())
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<*st.rbegin()<<endl;
        }
    }
    return(0);

}