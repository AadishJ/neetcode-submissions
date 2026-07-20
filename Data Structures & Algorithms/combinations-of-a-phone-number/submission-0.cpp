class Solution {
public:
    unordered_map<char,vector<char>> mp;
    string cur;
    vector<string> ans;
    string digits;
    vector<string> letterCombinations(string d) {
        digits=d;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        sol(0);
        return ans;
    }
    void sol(int ind){
        if(ind==digits.size()){
            if(!cur.empty())
            ans.push_back(cur);
            return;
        }
        cout << ind << ' ' << mp[digits[ind]].size() << endl;
        for(char c: mp[digits[ind]]){
            cur.push_back(c);
            sol(ind+1);
            cur.pop_back();
        }
    }
};
