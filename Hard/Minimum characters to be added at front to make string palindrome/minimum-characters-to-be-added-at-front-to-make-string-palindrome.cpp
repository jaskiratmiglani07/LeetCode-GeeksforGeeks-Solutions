//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
//how many minimum characters have to be added to the string so that it becomes a palindrome
//you can only add stuff to the beginning of the string.
//if we can somehow find the longest prefix pallindrome we can easily solve the problem since we just have to move the characters that are left out to the right of the longest prefix pallindrome to the beginning of the string and we've made a pallindrome.
//now let's say if we reverse the string given to us and try to find out the common prefix and suffix we can, we can get the longest prefix pallindrome. and to do that, we can use the lps stuff.
//we can apply lps if we put the reverse of the string directly attached to the OG string provided to us.
//do add a dollar sign in the middle of the transition between the reverse and straight.
        string rev=str;
        reverse(rev.begin(),rev.end());
        int size=str.size();
        str+='$';//separator
        str+=rev;//reverse
        //getting the lps of the combination
        int n=str.size();
        vector<int>lps(n,0);
        int pre=0, suf=1;
        while(suf<str.size())
        {
            if(str[pre]==str[suf])
            {
                lps[suf]=pre+1;
                pre++,suf++ ;
            }
            else
            {
                if(pre==0)
                suf++;
                else
                {
                    pre=lps[pre-1];
                }
            
            }
        }
        return size-lps[n-1];
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends