//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> st;

        // Push the first k elements into a stack
        for (int i = 0; i < k; ++i) {
            st.push(q.front());
            q.pop();
        }

        // Pop elements from the stack and push them back into the queue
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        // Move the remaining elements from the front to the back to maintain order
        int size = q.size();
        for (int i = 0; i < size - k; ++i) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends