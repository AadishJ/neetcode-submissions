class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                string op = tokens[i];
                cout << a << ' ' << b << ' ' << op << endl;
                if(op=="+") st.push(a+b);
                if(op=="-") st.push(b-a);
                if(op=="*") st.push(a*b);
                if(op=="/") st.push(b/a);
            }
        }
        return st.top();
    }
};
