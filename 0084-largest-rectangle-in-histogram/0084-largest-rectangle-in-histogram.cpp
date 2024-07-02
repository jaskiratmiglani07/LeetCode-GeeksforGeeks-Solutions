class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //method 1
//     stack<int>st;
//     vector<int>right(heights.size(),heights.size());//stores the indices of next smallest elements to the left
//     vector<int>left(heights.size(),-1);//stores the indices of next smallest elements to the right
//     for(int i=0; i<heights.size() ; i++)
//     {
//     while(!st.empty() && heights[st.top()]>heights[i])
//     {
//         right[st.top()]=i;
//         st.pop();
//     }
//     st.push(i);
//     }
//     for(int i=(heights.size()-1); i>=0 ; i--)
//     {
//     while(!st.empty() && heights[st.top()]>heights[i])
//     {
//         left[st.top()]=i;
//         st.pop();
//     }
//     st.push(i);
//     }
//     int ans=0;
//     for(int i=0; i<heights.size(); i++)
//     {
//     ans = max(ans, heights[i]*(right[i]-left[i]-1));
//     }
// return ans;
        //method 2
stack<int>st;
int index;
int ans=0;
int n=heights.size();
for(int i=0; i<heights.size() ; i++)
{
    while(!st.empty() && heights[st.top()]>heights[i])
    {   
        index= st.top();
        st.pop();
        if(!st.empty())
        ans=max(ans,heights[index]*(i-st.top()-1));
        else
        {
        ans=max(ans, heights[index]*i);
        }
    }
    st.push(i);
}
        while(!st.empty())
        {
            index = st.top();
            st.pop();
            if(!st.empty())
                ans = max(ans, heights[index]*(n-st.top()-1));
            else
                ans = max(ans, heights[index]*n);
        }
        return ans;
    }
};