#include<iostream>
#include<utility>
#include<map>

using namespace std;

int main()
{
    int n;
    cin>>n;

    pair<int,int> *arr = new pair<int,int>[n];

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y};
    }

    map<float,int> mp ;
    int ans = (n) * (n-1) * (n-2) / 6;
    


    for(int i = 0 ; i <n ;i ++)
    {
        int slope_inf = 0;
        mp.clear();
        for(int j = i+1; j<n ;j++)
        {

            pair<int,int> pt1 = arr[i];
            pair<int,int> pt2 = arr[j];

            int y_diff = pt2.second - pt1.second;
            int x_diff = pt2.first - pt1.first;

            if(x_diff == 0)
            {
                slope_inf++;
                continue;
            }
        
            float slope = (float)(y_diff)/(x_diff);
            mp[slope]++;
        }
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second > 1)
            {
                int temp = it->second;
                temp = (temp) * (temp-1) /2 ;
                ans-=temp;
            }
        }
        int temp = (slope_inf) * (slope_inf-1) /2 ;
        ans-=temp;
    }
    cout<<ans<<endl;
    return(0);


}


            