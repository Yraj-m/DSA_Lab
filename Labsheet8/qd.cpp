#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    set<int> st;

    while(q--)
    {
        int t , k;
        cin>>t>>k;
        switch(t)
        {
            case 1:
            if(st.find(k) != st.end())
            {
                st.erase(k);
            }
            else
            {
                st.insert(k);
            }
            break;

            case 2:
            if(k > *st.rbegin())
            {
                cout<<-1<<endl;
                break;
            }
            cout<<*st.lower_bound(k)<<endl;
            break;

            case 3:
            if(k < *st.begin())
            {
                cout<<-1<<endl;
                break;
            }
            auto pos = st.upper_bound(k);
            pos--;
            cout<<*pos<<endl;
            break;
        }

    }
    return(0);
}