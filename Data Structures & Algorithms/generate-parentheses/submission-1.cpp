class Solution {
   public:
    vector<char> temp;
    vector<string> ans;
    int num;
    vector<string> generateParenthesis(int n) {
        num = 2 * n;
        sol(0);
        return ans;
    }
    bool check(string& s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if ((c == ')' && st.top() != '(') || (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
    void sol(int i) {
        string s(temp.begin(), temp.end());
        if (i == num) {
            if(check(s))
            ans.push_back(s);
            return;
        }
        temp.push_back('(');
        sol(i + 1);
        temp.pop_back();
        temp.push_back(')');
        sol(i + 1);
        temp.pop_back();
    }
};
