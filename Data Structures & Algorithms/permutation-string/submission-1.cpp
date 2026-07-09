class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s1.size()>s2.size()) return false;
       vector<int> mp(27,0);
       for(char c: s1){
        mp[c-'a']++;
       }
       for(int i=0;i<=s2.size()-s1.size();i++){
       vector<int> mp2(27,0);
       bool pass=true;
        for(int j=i;j<i+s1.size();j++){
            mp2[s2[j]-'a']++;
        }
        for(int p=0;p<26;p++){
            if(mp2[p]<mp[p]){
                pass=false;
                break;
            }
        }
        if(pass) return true;
       }
       return false;
    }
};
