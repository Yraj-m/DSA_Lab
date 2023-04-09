#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
    string str;
    cin>>str;

    stack<char> stk;

    for(int i=0;i<str.length();i++)
    {
        if( !(stk.empty()) && str[i] == ')' && stk.top() == '(')
        {
            stk.pop();
        }
        else
        {
            stk.push(str[i]);
        }
    }
    printf("%d",stk.size());
    return(0);


}