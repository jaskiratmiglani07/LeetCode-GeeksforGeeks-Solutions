class Solution {
public:
    bool check(string str)
    {
    stack<char>st;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        st.push(str[i]);
        else
        {
            if(st.empty())
            return 0;
            char top = st.top();
            if((str[i] == ')' && top != '(') ||
                 (str[i] == '}' && top != '{') ||
                   (str[i] == ']' && top != '[')) {
                    return false;
            }
            else
            st.pop();
        }
    }
    return st.empty();
    }
    bool isValid(string s) {
        int val=check(s);
        return val;
    }
};