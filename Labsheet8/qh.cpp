#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main()
{
    string str;
    cin>>str;

    vector<string> subs ;
    vector<string> ans;

    //precompute substrings - O(10n)
    for(int i=0;i<=str.length()-10;i++)
    {
        string temp = str.substr(i,10);
        subs.push_back(temp);
    }

    map<string,int> mp;

    //fill into map - O(nlogn)
    for(auto it : subs)
    {
        string temp = it;
        mp[temp]++;
    }

    int count =0;

    //get count and create answer vector - O(n)
    for(auto it : mp)
    {
        if(it.second>1)
        {
            count++;
            ans.push_back(it.first);
        }
        
    }
    cout<<count<<endl;

    //print answer strings - O(n)
    for(auto it : ans)
    {
        cout<<it<<endl;
    }
    return(0);

}