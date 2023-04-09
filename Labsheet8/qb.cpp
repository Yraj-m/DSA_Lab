#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    string str;

    cin>>n;
    cin>>str;

    bool up = false;
    int i;
    if(n%2==0)
    {
        for(i=0;i<(n/2)-1;i++)
        {
            if(str[i] == str[n-i-1])
                continue;
            str[n-i-1] = str[i];
        }
        if(str[i]>str[i+1])
        {
            str[i+1] = str[i];
        }
        else
        {
            str[i] = str[i+1];
        }
    }
    else
    {
        for(i=0;i<(n/2);i++)
        {
            if(str[i] == str[n-i-1])
                continue;
            if(str[i]>str[n-i-1])
            {
                str[n-i-1] = str[i];
            }
            if(str[i]<str[n-i-1])
            {
                up=true;
                str[n-i-1] = str[i];
            }
        }
        if(up==true)
        {
            str[i] = char(str[i] + 1);
        }
    }
    cout<<str<<endl;
    return(0);

    
    

}