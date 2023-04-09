#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<set>

using namespace std;

int main()
{
    int n, k;
    int *arr1 = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    int *arr2 = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);

    priority_queue <pair<int , pair<int,int>>> pq;

    set <pair<int,int>> ind ;

    ind.insert(make_pair(n-1,n-1));
    pq.push(make_pair(arr1[n-1]+arr2[n-1], make_pair(n-1,n-1)));

    for(int cnt=0;cnt<k;cnt++)
    {
        pair<int,pair<int,int>> temp = pq.top();
        cout<<temp.first<<" ";

        int i = temp.second.first;
        int j = temp.second.second;

        pq.pop();

        pair<int,int> p1 = make_pair(i-1,j);
        pair<int,int> p2 = make_pair(i,j-1);

        pair<int,pair<int,int>> op;

        if(ind.find(p1) == ind.end());
        {
            op = make_pair(arr1[i-1]+arr2[j], p1);
            pq.push(op);
        }

        
        if(ind.find(p2) == ind.end());
        {
            op = make_pair(arr1[i]+arr2[j-1], p2);
            pq.push(op);
        }
    }

    return(0);

}