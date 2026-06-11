class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        // Push boundary O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }

            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                q.push({m - 1, j});
            }
        }

        int rd[] = {0, 0, 1, -1};
        int cd[] = {-1, 1, 0, 0};

        // BFS from boundary O's
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int rr = r + rd[k];
                int cc = c + cd[k];

                if (rr >= 0 && rr < m && cc >= 0 && cc < n && board[rr][cc] == 'O') {
                    board[rr][cc] = '#';
                    q.push({rr, cc});
                }
            }
        }

        // Convert
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
