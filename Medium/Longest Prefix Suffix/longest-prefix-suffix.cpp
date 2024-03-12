//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int>lps(s.size(),0);
	    int prefix=0, suffix=1;
	    while(suffix<s.size())
	    {
	        if(s[prefix]==s[suffix])
	        {
	            lps[suffix]=prefix+1;
	            prefix++, suffix++;
	        }
	        else
	        {
	            if(prefix==0)
	            {   lps[suffix]=0;
	                suffix++;
	            }
	            else
	            {
	                prefix=lps[prefix-1];//crux
	            }
	        }
	    }
	    return lps[s.size()-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends