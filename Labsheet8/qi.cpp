#include<iostream>
#include<map>
#include<utility>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[y]++;
    }
    for(int i = 1 ;i<=k;i++)
    {
        if(mp.find(i) != mp.end())
        {
            if(mp[i]>1)
            {
                continue;
            }
        }
        cout<<i<<" ";
    }
    return(0);
    
}