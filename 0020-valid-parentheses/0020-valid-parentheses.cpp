class Solution {
public:
bool check(string str)
{
    stack<char>s;
    for(int i=0; i<str.size(); i++)
    {
        if((str[i]=='(')||(str[i]=='{')||(str[i]=='['))
        s.push(str[i]);
        else
        {
            if(s.empty())
            return 0;
            char top = s.top();
            if((str[i]==')'&& top!='(')||(str[i]=='}'&& top!='{')||(str[i]==']'&& top!='['))
            return false;
            else
            s.pop();
        }
    }
    return s.empty();
}
    bool isValid(string s) {
        int val=check(s);
        return val;
    }
};