//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
// code here 
    stack<int>st;
    for(int i=n-1; i>=0; i--)
    {
        st.push(i);
        while(st.size()>1)
        {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if( M[first][second] && !M[second][first])
            st.push(second);
            else if( !M[first][second] && M[second][first])
            st.push(first);
        }
    }
    //there is no element left in the stack
    if(st.empty())
    return -1;
    //there is one element left in the stack
    //confirming if the element left is the celebrity 
    //the sum of all elements present in celebrity's row equals 0 and the sum of all elements present in celebrity's column equals n-1
    int num = st.top();
    st.pop();
    int row=0, col=0;
    for(int i=0; i<n; i++)
    {
        row = row + M[num][i];
        col = col + M[i][num];
    }
    return row==0 && col==n-1 ? num : -1;//using the ternary operator to display result
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends