class Solution {
public:
    int findMin(vector<int> &nums) {
        int low =0,high=nums.size()-1,mid=0;
        if(nums[low]<nums[high]) return nums[low];
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[low]>nums[high] && nums[mid]>nums[low]){
                low=mid;
            }else if(nums[low]>nums[high] && nums[mid]<nums[low]){
                high=mid;
            }else{
                return nums[high];
            }
        }   
        return nums[low];
    }
};
