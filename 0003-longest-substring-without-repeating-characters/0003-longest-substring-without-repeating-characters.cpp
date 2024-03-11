class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int first=0, second=0, length=0;
        while(second<s.size())
        {
            while(count[s[second]])
//This loop condition checks whether the character at index second in the string s has been encountered before in the current substring. If it has (count[s[second]] evaluates to true), it means the character is a repetition and the operation written below will be performed.
            {
                count[s[first]]=0;
                first++;
            }
            count[s[second]]=1;
            length=max(length, second-first+1);
            second++;
        }
        return length;
    }
};