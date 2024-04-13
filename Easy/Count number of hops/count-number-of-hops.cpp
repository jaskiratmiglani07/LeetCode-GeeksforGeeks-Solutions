//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
   long long countWays(int n)
{
    const int MOD = 1000000007;
    if(n <= 1)
        return 1;
    if(n == 2)
        return 2;
    if(n == 3)
        return 4;

    long long first = 1, second = 2, third = 4, nth_term = 0;
    for(int i = 4; i <= n; i++)
    {
        nth_term = (first + second + third) % MOD;
        first = second;
        second = third;
        third = nth_term;
    }
    return nth_term;
}

};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends