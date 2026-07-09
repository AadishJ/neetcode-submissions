class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(char c: s){
            if((c>='A' && c<='Z' )||(c>='a' && c<='z') || (c>='0' && c<='9') ){
                ans+=tolower(c);
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=ans[ans.size()-i-1]) return false;
        }
        return true;
    }
};
