class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char, int> mp;
        int st = 0;
        int e = 0;
        int ans=0;
        while (e < s.size() && st < s.size()) {
            while (st<s.size() && mp.contains(s[e])) {
                mp[s[st]]--;
                if (mp[s[st]] == 0) mp.erase(s[st]);
                st++;
            }
            mp[s[e++]]++;
            ans=max(ans,e-st);
        }
        return ans;
    }
};
