//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> st1;
    stack<int> st2;
    public:
void push(int x)
{
    if(st1.empty())
    {
        st1.push(x);
        st2.push(x);
    }
    else
    {
        st1.push(x);
        st2.push(min(x,st2.top()));
    }
}
int pop()
{
    if(st1.empty())
    return -1;
    else
    {
        int element = st1.top();
        st1.pop();
        st2.pop();
        return element;
    }
}
int getMin()
{
    if(st1.empty())
    return -1;
    else
    {
        return st2.top();
    }
}
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends