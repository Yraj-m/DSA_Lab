#include<iostream>
using namespace std;

class MinStack{

    public:
    int tos;
    int minEle;
    int stack[1000];

    MinStack()
    {
        tos=-1;
    }

    void push(int val);
    void pop();
    int top();
    int getMin();

};

void MinStack::push(int val)
{
    if(tos == -1)
        minEle = val;

    tos++;
    if(val >= minEle)
        stack[tos] = val;
    else{
        stack[tos] = (2*val - minEle);
        minEle = val;
    }
}
void MinStack::pop()
{
    int val = stack[tos];
    if(val < minEle)
        minEle = (2*minEle - val);
    tos--;
}
int MinStack::top()
{
    return(stack[tos]);
}
int MinStack::getMin()
{
    return(minEle);
}

int main()
{
    MinStack st;
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
            int num;
            cin>>num;
            st.push(num);
            break;
            case 2:
            st.pop();
            break;
            case 3:
            cout<<st.top()<<endl;
            break;
            case 4:
            cout<<st.getMin()<<endl;
            break;
        }
    }
    return(0);
}
