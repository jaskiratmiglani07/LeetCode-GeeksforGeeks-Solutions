class Solution {
public:
    bool isPalindrome(int x) {
    if(x<0)
        return 0;
       string num=to_string(x);
        int n=num.size();
     for(int i=0; i<num.size(); i++)
     {
        if(num[i]!=num[n-i-1])
        {
            return 0;
        }
        
     }
return 1;
    }
};