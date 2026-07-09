class Solution {
public:
    bool isAnagram(string s, string t) {
        int f1[26]={0},f2[26]={0};
        for(char c: s){
            f1[c-'a']++;
        }
        for(char c: t){
            f2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i]) return false;
        }
        return true;
    }
};
