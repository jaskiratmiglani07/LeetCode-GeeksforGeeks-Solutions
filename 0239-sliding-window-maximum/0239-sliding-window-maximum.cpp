class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //method 1, brute force approach 
        //gave timelimit exceeded
        // vector<int>ans;
        // for(int i = 0; i<=nums.size()-k; i++)
        // {
        //     int total = INT_MIN;
        //     for(int j=i; j<i+k; j++)
        //     {
        //          total = max(total, nums[j]);
        //     }
        //     ans.push_back(total);
        // }
        // return ans;
        //method 2
        //pop back the previous element if it is smaller than whatever is kept on the current index
        //if the front element is not a part of the window, pop it
        //get ans
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        for(int i=0; i<k-1 ; i++)
        {
            if(dq.empty())
                dq.push_back(i);
            else
            {
                while(!dq.empty() && nums[i]>nums[dq.back()])
                    dq.pop_back();
                dq.push_back(i);
            }
        }
        for(int i=k-1; i<n; i++)
        {
            //1)pop back the previous element if it is smaller than whatever is kept on the current index
            while(!dq.empty() && nums[i]>nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            //2)if the front element is not a part of the window, pop it
            if(dq.front()<=i-k)       
                dq.pop_front();
            //3)push the element kept at dq's front element's index in nums array into ans vector
            ans.push_back(nums[dq .front()]);
        }
        return ans;
    }
};

