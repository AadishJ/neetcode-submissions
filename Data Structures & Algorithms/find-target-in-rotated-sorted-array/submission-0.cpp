class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = findMin(nums);
        int low=0,high=min,mid=0;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                return mid;
            }
        }
        low=min,high=nums.size()-1,mid=0;
        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
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
                return high;
            }
        }   
        return -1;
    }
};
