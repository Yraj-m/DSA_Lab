
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

string sortStr(string st, int m)
{
    int alph[26] = {0};
    for(char ch : st)
    {
        alph[ch-'a']++;
    }
    string my;
    for(int i = 0;i<26;i++)
    {
        char temp = char('a' + i) ;
        while(alph[i]!=0)
        {
            my.push_back(temp);
            alph[i]--;
        }

    }
    return(my);

}


int main()
{
    int n,m;
    cin>>n>>m;

    string* arr = new string[n];
    string* arr_sort = new string[n];
    
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    unordered_map<string,int> um ;

    for(int i=0;i<n;i++)
    {
        string str = arr[i];
        string my_str = sortStr(str,m);
        um[my_str]++;
    }

    int ans;
    for(auto it = um.begin() ; it!=um.end();it++)
    {
        int n = it->second;
        if(n>1)
        {
            ans+= (n*(n-1)/2);
        }
    }
    cout<<ans<<endl;
    return(0);

}