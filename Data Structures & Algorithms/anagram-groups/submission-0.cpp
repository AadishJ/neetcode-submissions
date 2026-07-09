class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<vector<int>> f(strs.size(),vector<int>(26,0));
        for(int i=0;i<strs.size();i++){
            for(char c: strs[i]){
                f[i][c-'a']++;
            }
        }
        unordered_set<int> s;
        for(int i=0;i<f.size();i++){
            if(s.contains(i)) continue;
            s.insert(i);
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j=i+1;j<f.size();j++){
                if(f[i]==f[j]){
                    temp.push_back(strs[j]);
                    s.insert(j);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
