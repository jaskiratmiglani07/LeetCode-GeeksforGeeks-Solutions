class Solution {
public:
bool compareVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}
    bool backspaceCompare(string str1, string str2) {
        stack<char>s1;
        stack<char>s2;
    for(int i=0; i<str1.size(); i++)
    {
        if(str1[i]!='#')
        s1.push(str1[i]);
        else
        {
            if(!s1.empty())
            s1.pop();
        }
    }
    for(int i=0; i<str2.size(); i++)
    {
        if(str2[i]!='#')
        s2.push(str2[i]);
        else
        {
            if(!s2.empty())
            s2.pop();
        }
    }
    vector<int>v1(s1.size());
    int i = s1.size()-1;
    while(!s1.empty())
    {
        v1[i]=s1.top();
        i--;
        s1.pop();
    }
    vector<int>v2(s2.size());
    i = s2.size()-1;
    while(!s2.empty())
    {
        v2[i]=s2.top();
        i--;
        s2.pop();
    }
    int ans = compareVectors(v1,v2);
        return ans;

    }
};