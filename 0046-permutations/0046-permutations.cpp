class Solution {
public:
void permut(vector<int>&arr, vector<vector<int> >&ans, int index)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index; i<arr.size(); i++)
    {
        swap(arr[i],arr[index]);
        permut(arr,ans, index+1);//once the function call is over, put it back to its original place
        swap(arr[i],arr[index]);
    }
}  
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int> >ans;
int index=0;
         permut(nums,ans,index);
         return ans;
    }
};