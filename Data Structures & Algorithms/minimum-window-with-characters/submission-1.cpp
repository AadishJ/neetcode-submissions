class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> sm,tm;
        for(char c: t){
            tm[c]++;
        }
        int st=0,en=0,size=INT_MAX,b=-1,e=-1;
        while(en<s.size()){
            while(en<s.size() && !comp(tm,sm)){
                sm[s[en++]]++;
            }
            while(st<s.size() && comp(tm,sm)){
                sm[s[st]]--;
                if(sm[s[st]]==0) sm.erase(s[st]);
                st++;
            }  
            if(size>en-st){
                size=en-st;
                b=st-1;
                e=en;
            }
        }
        if(b==-1 || e==-1) return "";
        string ans = s.substr(b,e-b);
        return ans;
    }
    bool comp(unordered_map<char,int>& m1,unordered_map<char,int>& m2){
        for(auto it: m1){
            if(it.second>m2[it.first]){
                return false;
            }
        }
        return true;
    }
};
