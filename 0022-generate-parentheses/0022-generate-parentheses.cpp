class Solution {
public:
void parenthesis(int n, int open, int close,vector<string>&ans, string &temp)
    {   
        //base condition
    if(open+close==2 * n)
    {
        ans.push_back(temp);
        return ;
    }
        //open parenthesis
        if(open<n)
        {
            temp.push_back('(');
            parenthesis(n,open+1,close,ans,temp);
            temp.pop_back();
        }
        //close parenthesis
        if(close<open)
        {
            temp.push_back(')');
            parenthesis(n,open,close+1,ans,temp);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        parenthesis(n,0,0,ans,temp);
        return ans;
    }
};