//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> &arr, int n) {
        stack<int> st;  // Stack to keep indices
        vector<long long> ans(n, -1);  // Result vector initialized with -1

        for (int i = 0; i < n; i++) {
            // While stack is not empty and current element is greater than the element at index stored in stack
            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = arr[i];  // Update result for index at top of the stack
                st.pop();  // Pop the index from the stack
            }
            st.push(i);  // Push the current index onto the stack
        }
        return ans;  // Return the result vector
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends