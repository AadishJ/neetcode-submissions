class Solution {
public:
    bool isPalindrome(string s) {
        int st=0,en=s.size()-1;
        while(st<en){
            while(st<s.size() && !((s[st]>='A' && s[st]<='Z' )||(s[st]>='a' && s[st]<='z') || (s[st]>='0' && s[st]<='9') ))st++;
            while(en>=0 && !((s[en]>='A' && s[en]<='Z' )||(s[en]>='a' && s[en]<='z') || (s[en]>='0' && s[en]<='9')) )en--;
            if(st<s.size() && en>=0 && st<en && tolower(s[st])!=tolower(s[en])){
                return false;
            }else{
                st++;
                en--;
            }
        }
        return true;
    }
};
