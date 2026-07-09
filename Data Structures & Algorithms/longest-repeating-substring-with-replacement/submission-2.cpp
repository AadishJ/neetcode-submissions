class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char c = 'A';c<='Z';c++){
            ans=max(sol(s,k,c),ans);
        }
        return ans;
    }
    int sol(const string& s, int k, char c){
        int st=0;
        int en=0;
        int ans=0;
        while(en<s.size()){
            while(k==0 && s[en]!=c){
                if(s[st]!=c) k++;
                st++;
            }
            while(en < s.size() && s[en]==c){
                en++;
            }
            while(k!=0 && en<s.size() && s[en]!=c){
                k--;
                en++;
            }
            ans=max(en-st,ans);
        }
        return ans;
    }
};
