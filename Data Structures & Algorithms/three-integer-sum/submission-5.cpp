class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<pair<pair<int,int>,int>> ans;
        vector<vector<int>> ans2;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;
            int t = -nums[i];
            while(j<k){
                if(nums[j]+nums[k]>t){
                    k--;
                }else if(nums[j]+nums[k]<t){
                    j++;
                }else{
                    ans2.push_back({nums[i],nums[j],nums[k]});

            while(j < k && nums[j] == nums[j+1]) j++;
            while(j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans2;
    }
};
