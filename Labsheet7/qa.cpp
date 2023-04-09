#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int ans=0;
    
    priority_queue <int> pq;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }

    for(int i=0;i<m;i++)
    {
        int val = pq.top();
        pq.pop();
        pq.push(val/2);
    }
    while(!(pq.empty()))
    {
        int val = pq.top();
        ans+=val;
        pq.pop();
    }
    cout<<ans<<endl;
    return(0);

}