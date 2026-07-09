class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<pair<pair<int,int>,int>> ans;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            int t = -nums[i];
            while(j<k){
                if(nums[j]+nums[k]>t){
                    k--;
                }else if(nums[j]+nums[k]<t){
                    j++;
                }else{
                    ans.insert({{nums[i],nums[j]},nums[k]});
                    j++;
                    k--;
                }
            }
        }
        vector<vector<int>> ans2;
        for(auto it: ans){
            ans2.push_back({it.first.first,it.first.second,it.second});
        }
        return ans2;
    }
};
