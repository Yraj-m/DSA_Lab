#include<iostream>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, pair<int,int>> elem;



int main()
{
    int k;
    cin>>k;

    int** arr = new int*[k];
    int *ind = new int[k];

    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        ind[i]=x;
        arr[i] = new int[x];
        for(int j =0;j<x;j++)
        {
            cin>>arr[i][j];
        }
    }



    priority_queue <elem,vector<elem>,greater<elem>> pq;

    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    
    while(!(pq.empty()))
    {
        elem curr = pq.top();
        pq.pop();

        int val = curr.first;
        int arr_no = curr.second.first;
        int ind_no = curr.second.second;

        cout<<val<<" ";
        if(ind_no != ind[arr_no] -1)
        {
            pq.push({arr[arr_no][ind_no+1] , {arr_no,ind_no+1}});
        }
    }


    return(0);


}