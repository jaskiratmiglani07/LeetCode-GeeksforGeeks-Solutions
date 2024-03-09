//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

bool find4Numbers(int A[], int n, int X)  
{
    sort(A,A+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int start=j+1,end=n-1;


            while(start<end){
                int sum=A[i]+A[j]+A[start]+A[end];
                if(sum==X)
                return 1;
                else if(sum>X)
                end--;
                else
                start++;
            }
        }
    }
    return 0;
    
}