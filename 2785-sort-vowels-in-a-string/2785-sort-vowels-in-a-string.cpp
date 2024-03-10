class Solution {
public:
    string sortVowels(string s) {
        vector<int>lower(26,0);
        vector<int>upper(26,0);
        for(int i=0; i<s.size(); i++)
        {   
            //lower a e i o u
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {lower[s[i]-'a']++;
             s[i]='#';
            }
            //upper A E I O U
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {upper[s[i]-'A']++;
            s[i]='#';
            }
        }   
        string answer;
        //uppercase 
//uppercase is covered first because it has been mentioned in the question that we have to take the characters that have a smaller ascii value before.
        for( int i=0; i<26; i++)
        {
            
            char c= 'A'+i;
            while(upper[i])
            {
                answer+=c;
                upper[i]--;
            }
        }
        //lowercase
        for( int i=0; i<26; i++)
        {
            
            char c= 'a'+i;
            while(lower[i])
            {
                answer+=c;
                lower[i]--;
            }
        }
        int first=0;//first is pointing to the OG string s 
        int second=0;//second is pointing to the string named answer
        while(second<answer.size())
        {
            if(s[first]=='#')
            {
                s[first]=answer[second];
                second++;
            }
            first++; 
        }
        return s;
    }
};