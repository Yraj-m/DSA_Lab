#include<iostream>
#include<map>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x,y;
    


    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cin>>x>>y;
    int ans=0;

    map<int,int> mp;

    mp[arr[0]]++;



    for(int i=1;i<n;i++)
    {
        int temp_y = arr[i] - (y*i);
        ans+= mp[temp_y];

        int temp_x = arr[i] - (x*i);
        mp[temp_x]++;
    }
    cout<<ans<<endl;
    return(0);


}