#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }


    int xorr = 0;
    int ans = 0;


    map <int,int> mp;

    for(int i=0;i<n;i++)
    {
        xorr = xorr ^ arr[i];
        if(xorr == 0)
        {
            ans++;
        }
        if(mp[xorr] > 0)
        {
            ans += mp[xorr];
        }
        mp[xorr]++;
    }
    cout<<ans<<endl;
    return(0);




}