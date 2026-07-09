class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> a;
        for(int i=0;i<nums.size();i++){
            a[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            int t = target-nums[i];
            if(a.contains(t)){
                if(nums[i]==t){
                if(a[t].size()==2) return {i,a[t][1]};
                else continue;
                }
                else return {i,a[t][0]};
            }
        }
        return {-1,-1};
    }
};
