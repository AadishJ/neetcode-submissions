class Solution {
public:
    vector<vector<string>> ans;
    vector<int> temp;
    int n;
    vector<vector<string>> solveNQueens(int ns) {
        n=ns;
        temp.resize(n);
        sol(0);
        return ans;
    }
    bool check(int col, int row){
        for(int i=0;i<row;i++){
            if(temp[i]==col) return false;
        }
        for(int i=0;i<row;i++){
            int r = i;
            int c = temp[i];
            if(abs(col-c)==abs(row-r)){
                return false;
            }
        }
        return true;
    }
    vector<string> toBoard(){
        vector<string> a;
        for(int i=0;i<temp.size();i++){
        string s;
        int c = temp[i];
        for(int j=0;j<temp.size();j++){
            if(c==j) s+='Q';
            else s+='.';
        }
        a.push_back(s);
        }
        return a;
    }
    void sol(int ind){
        if(ind==n){
            ans.push_back(toBoard());
            return;
        }
        for(int i=0;i<n;i++){
            if(check(i,ind)){
                temp[ind]=i;
                sol(ind+1);
                temp[ind]=-1;
            }
        }
    }
};
