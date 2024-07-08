//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

                        int FirstNegativeInteger(queue<int>q)
                        {
                            while(!q.empty())
                            {
                                if(q.front()<0)
                                {
                                    return q.front();
                                }
                                else
                                {
                                    q.pop();
                                }                            
                                
                            }
                            return 0;
                                
                        }
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
//method 1 with time complexity O(NK), gave runtime error
                    //     queue<int>q;
                    //     vector<long long>ans;
                    //     for(int i=0; i<K-1; i++)
                    //     {
                    //         q.push(A[i]);
                    //     }
                    //     for(int i=K-1; i<N; i++)
                    //     {
                    //         q.push(A[i]);
                    //         ans.push_back(FirstNegativeInteger(q));
                    //         q.pop();
                    //     }
                    // return ans;
//method 2
    //1) only push the index to q if A[i] is negative
    //2) if q is empty, print 0
    //  is q.front() a part of current window?
    //  if q.front() is less than or equal to (i-K), pop q.front() otherwise print q.front() if the queue is not empty(if it is empty, print 0)
                    queue<int>q;
                    vector<long long>ans;
                    for(int i = 0; i<K-1; i++)
                    {
                        if(A[i]<0)
                        q.push(i);
                    }
                    for(int i=K-1; i<N; i++)
                    {
                        if(A[i]<0)
                        q.push(i);
                        if(q.empty())
                        ans.push_back(0);
                        else
                        {
                        //checking if q.front() is part of the window or not
                            if(q.front()<=(i-K))//popping it if it is not part of window
                            q.pop();
                            if(q.empty())
                            ans.push_back(0);
                            else
                            ans.push_back(A[q.front()]);
                        }
                    }
                    return ans;
 }