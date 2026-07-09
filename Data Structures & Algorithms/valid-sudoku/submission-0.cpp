class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            if(!check(board[i])) return false;
        }
        for(int i=0;i<board.size();i++){
            unordered_set<char> s(9);
            for(int j=0;j<board.size();j++){
                if(s.contains(board[j][i])) return false;
                if(board[j][i]!='.')
                s.insert(board[j][i]);
            }
            s.clear();
        }
        for(int i=0;i<9;i++){
            unordered_set<char> s(9);
            for(int x=(i/3)*3;x<((i/3)*3)+3;x++){
                for(int y=((i)*3)%9;y<(((i)*3))%9+3;y++){
                    if(s.contains(board[x][y])) return false;
                    if(board[x][y]!='.')
                    s.insert(board[x][y]);
                }
            }
            s.clear();
        }
        return true;
    }
    bool check(vector<char>& b){
        unordered_set<char> s(9);
        for(char c: b){
            if(s.contains(c)) return false;
            if(c!='.')
            s.insert(c);
        }
        return true;
    }
};
