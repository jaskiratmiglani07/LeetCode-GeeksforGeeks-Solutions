class Solution {
public:
void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp(end-start+1);
    int left=start, right=mid+1, index=0;
    while(left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp[index]=arr[left];
            index++,left++;
        }
        else
        {
            temp[index]=arr[right];
            index++, right++;
        }
    }
//if left array contains any leftover elements, copy them into temp
    while(left<=mid)
    { 
        temp[index]=arr[left];
        index++,left++;
    }
//if right array contains any leftover elements, copy them into temp
    while(right<=end)
    {
        temp[index]=arr[right];
        index++,right++;
    }
//putting the values in arr
    index=0;
    while(start<=end)
    {
        arr[start]=temp[index];
        start++,index++;
    }
}
void mergeSort(vector<int> &arr, int start, int end)
{   
    if(start==end)
    return;
    int mid= start+ (end-start)/2; //to-prevent-integer-overflow
    mergeSort(arr,start,mid);//divided left
    mergeSort(arr,mid+1,end);//divied right
    merge(arr,start,mid,end); 

}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort( nums, 0, nums.size()-1);
        return nums;
    }
};