class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);
    
//getting the frequency of each character present in the string s
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='a')
//ascii value of 'A' is 65 so all the capital characters would be smaller than 'a' and hence they will be stored in the 'upper' vector automatically.
            lower[(s[i]-'a')]++;
            else
            upper[(s[i]-'A')]++;
        }
        int count=0; 
        bool odd=0;
        for(int i=0; i<26 ; i++)
        {
            //lowercase
            if(lower[i]%2==0)
            count+=lower[i];
            else
            {
                odd=1;
                count+=lower[i]-1;
            }
            //uppercase
            if(upper[i]%2==0)
            count+=upper[i];
            else
            {
                odd=1;
                count+=upper[i]-1;
            }
        }
        return count+odd;

    }
};