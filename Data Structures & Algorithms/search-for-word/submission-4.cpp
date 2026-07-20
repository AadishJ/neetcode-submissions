class Solution {
   public:
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool ans = false;
    vector<vector<char>> b;
    string w;
    string cur;
    vector<vector<int>> vis;
    bool exist(vector<vector<char>>& board, string word) {
        w = word;
        b = board;
        vis.assign(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    cur.push_back(word[0]);
                    vis[i][j]=1;
                    sol(i, j);
                    cur.pop_back();
                    vis[i][j]=0;
                    if (ans) return ans;
                }
            }
        }
        return ans;
    }
    void sol(int x, int y) {
        cout << cur << endl;
        if (ans) return;
        if (cur.size() == w.size()) {
            if (cur == w) {
                ans = true;
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < b.size() && ny < b[0].size() && nx >= 0 && ny >= 0 &&
                w[cur.size()] == b[nx][ny] && !vis[nx][ny]) {
                cur.push_back(b[nx][ny]);
                vis[nx][ny] = 1;
                sol(nx, ny);
                vis[nx][ny] = 0;
                cur.pop_back();
            }
        }
    }
};
