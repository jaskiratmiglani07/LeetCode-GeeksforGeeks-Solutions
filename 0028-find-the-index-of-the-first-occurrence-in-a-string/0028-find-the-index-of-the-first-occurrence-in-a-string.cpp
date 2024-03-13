class Solution {
public:
   void lpsfind(vector<int>&lps,string s) {
	    // Your code goes here

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
   }
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.size(),0);
        lpsfind(lps,needle);
        int first=0, second=0;
        while(second<needle.size()&&first<haystack.size())
        {
            if(needle[second]==haystack[first])
            {
                second++,first++;
            }
            else
            {
                if(second==0)
                {
                    first++;
                }
                else
                {
                    second=lps[second-1];
                }
            }
        }
        if(second==needle.size())
            return first-second;
        else
            return -1;
    }
};