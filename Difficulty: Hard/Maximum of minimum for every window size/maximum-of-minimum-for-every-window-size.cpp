//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        //method 1
        //time complexity O(n^3)
//     vector<int>ans(n,0);
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n-i; j++)
//         {
//             int num = INT_MAX;
//             for(int k=j; k<j+i+1; k++)
//             {
//                 num = min(num, arr[k]);
//             }
//         ans[i] = max(ans[i],num);
//         }
//     }
// return ans;
// }
//method 2
//time complexity O(n)
vector<int>ans(n,0);
stack<int>st;
int range;
for(int i=0; i<n; i++)
{
    while(!st.empty() && arr[st.top( )]>arr[i])
    {
        int index = st.top();//for the index, the NSR is 'i' and the NSL is 'st.top()' after 'st.pop()'
        st.pop();
        if(st.empty())
        {
        range = i;//NSR-NSL-1 = NSR-(-1)-1 = NSR
        ans[range-1] = max(ans[range-1], arr[index]);
        }
        else
        {
        range = i - st.top() - 1;//NSR-NSL-1
        ans[range-1] = max(ans[range-1], arr[index]);
        }
    }
    st.push(i);
}
while(!st.empty())
{
    int index = st.top();
    st.pop();
    if(st.empty())
    {
        range = n;//NSR = n & NSL = -1
        ans[range-1] = max(ans[range-1],arr[index]);
    }
    else
    {
        range = n-st.top()-1;
        ans[range-1] = max(ans[range-1], arr[index]);
    }
}
for(int i = n-2; i>=0; i--)
{
    ans[i] = max(ans[i], ans[i+1]);
}
return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends