class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for(int i:nums){
            if(n.contains(i)) return true;
            n.insert(i);
        }
        return false;
    }
};