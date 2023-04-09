#include<iostream>
#include<queue>

using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;

    int ans = 0;
    int give=0;
    priority_queue <int> pq;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }
    for(int i=0;i<k;i++)
    {
        int temp = pq.top();

        if(temp%2==0)
        {
            give = temp/2;
        }
        else
        {
            give = temp/2 + 1;
        }
        ans+=give;
        pq.pop();
        temp = temp - give;
        pq.push(temp);
    }

    cout<<ans<<endl;
    return(0);

}