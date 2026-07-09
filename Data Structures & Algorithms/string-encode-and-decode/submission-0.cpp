class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string st: strs){
            s+=st;
            s+="\n";
        }
        return s;
    }

    vector<string> decode(string s) {
        stringstream st(s);
        string temp;
        vector<string> ans;
        while(getline(st,temp,'\n')){
            ans.push_back(temp);
        }
        return ans;
    }
};
