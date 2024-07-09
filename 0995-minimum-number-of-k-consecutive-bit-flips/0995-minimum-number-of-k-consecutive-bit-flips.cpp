class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        //method 1
        //time limit exceeded O(nk)
        // int flip = 0;
        // int n = nums.size();
        // for(int i=0; i<n; i++ )
        // {
        //     if(nums[i]==0)
        //     {
        //         if(i+k-1>=n)
        //             return -1;
        //         for(int j=i; j<=i+k-1; j++)
        //         {
        //             nums[j] = !nums[j];
        //         }
        //         flip++;
        //     }
        // }
        // return flip++;
        //method 2
        queue<int>q;
        int n = nums.size();
        int flip = 0; 
        for(int i=0; i<n ; i++)
        {
            if(!q.empty() && q.front()<i)
                q.pop();
            if(q.size()%2 == nums[i])//the master
            {
                if(i+k-1>=n)
                    return -1;
                q.push(i+k-1);
                flip++;
            } 
        }
        return flip;
    }
};