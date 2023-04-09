#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string str,word;
    cin>>str;

    stack<string> stk;

    word.clear();
    
    for(int i=0;i<str.length();i++)
    {
            while(str[i] == '/')
            {
                if(i == str.length()-1)
                    break;
                i++;
            }
            if(i == str.length()-1)
                    break;
            if(str[i] == '.')
            {
                if(str[i+1] == '.')
                {
                    stk.pop();
                    i++;
                }
                continue;
            }

            while(str[i]!='/')
            {
                word.push_back(str[i]);
                i++;
            }

            stk.push(word);
            word.clear();
            i--;


    }

    string final ="";
    if(stk.empty())
    {
        cout<<"/"<<endl;
    }
    while(!stk.empty())
    {
        string temp = stk.top();
        final = "/" + temp + final;
        stk.pop();
    }
    cout<<final<<endl;
    


    return(0);
}