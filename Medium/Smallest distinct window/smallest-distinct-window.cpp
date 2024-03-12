//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        
        // Your code goes here   
        vector<int>count(256,0);
        int first=0, second=0, len=str.size(), uniqueChar=0;
        //calculating the number of unique characters that are present in the string str
        while(first<str.size())
        {
            if(count[str[first]]==0)
            {uniqueChar++;

            }            
            count[str[first]]++;
            first++;
        }
        for(int i=0; i<256; i++)
        {
            count[i]=0;
            
        }
        first=0;
        while(second<str.size())
        {
            //this condition will run until uniqueChar turns 0
            while(uniqueChar&&second<str.size())
            {
                if(count[str[second]]==0)
                uniqueChar--;
                count[str[second]]++;
                second++;
            }
            len=min(len,second-first);
            
            while(uniqueChar!=1)
            {
                len=min(len,second-first);
                count[str[first]]--;
                if(count[str[first]]==0)
                {
                    uniqueChar++;
                }
                first++;
                
            }
          
        }
          return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends