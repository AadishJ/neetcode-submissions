#include <bits/stdc++.h>
using namespace std;

// ---------- pair ----------
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// ---------- tuple ----------
template<typename Tuple, size_t... Is>
void printTuple(ostream& os, const Tuple& t, index_sequence<Is...>) {
    ((os << (Is ? ", " : "") << get<Is>(t)), ...);
}

template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << "(";
    printTuple(os, t, index_sequence_for<Args...>{});
    return os << ")";
}

// ---------- iterable containers ----------
template<typename T, typename = decltype(begin(declval<T>())),
         typename = enable_if_t<!is_same_v<T, string>>>
ostream& operator<<(ostream& os, const T& container) {
    os << "[";
    bool first = true;
    for (const auto& x : container) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    return os << "]";
}
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> lind(heights.size());
        vector<int> rind(heights.size());
        stack<int> st,st2;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                lind[st.top()]=i-1;
                st.pop();
            }
            st.push(i);
            while(!st2.empty() && heights[st2.top()]>heights[heights.size()-i-1]){
                rind[st2.top()]= heights.size()-i-1;
                st2.pop();
            }
            st2.push(heights.size()-i-1);
        }
        while(!st.empty()){
            lind[st.top()]=heights.size()-1;
            st.pop();
        }
        while(!st2.empty()){
            rind[st2.top()]=-1;
            st2.pop();
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max({ans,(lind[i]-rind[i])*heights[i],heights[i]});
        }
        cout << rind << endl << lind << endl;
        return ans;
    }
};
