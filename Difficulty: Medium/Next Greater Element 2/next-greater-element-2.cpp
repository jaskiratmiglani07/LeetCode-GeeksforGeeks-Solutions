//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        // code here
    stack<int>st;
    vector<int>ans(N,-1);
    for(int i=0; i<(2*N) ; i++)
    {
        while(!st.empty()/*stack should not be empty*/ && arr[st.top()]<arr[i%N])
    {
        ans[st.top()]=arr[i%N];
        st.pop();
    }
    if(i<N)
    st.push(i);
    }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends