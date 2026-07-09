class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int curr=0,ans=0;
        for(int i: nums){
            curr=1;
            while(s.contains(i+1)) {curr++;i++;}
            ans=max(curr,ans);
        }
        return ans;
    }
};
