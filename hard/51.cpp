#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;

        vector<string> board(n, string(n, '.'));

        dfs(board, 0, n, answer);

        for (auto i : answer) {
            for (auto j : i) {
                cout << j << endl;
            }
            cout << endl;
        }

        return answer;
    }

   private:
    void dfs(vector<string> &board, int row, int n,
             vector<vector<string>> &answer) {
        // terminate
        if (row == n) {
            // add answer to answerBoard
            answer.push_back(board);

            return;
        }

        // cout << "backtraking: " << row << endl;
        // add queen one by one on the row
        for (int i = 0; i < n; ++i) {
            if (checkValid(board, row, i)) {
                // cout << "valid" << endl;
                board[row][i] = 'Q';
                dfs(board, row + 1, n, answer);
                board[row][i] = '.';
            }
        }
    }

    bool checkValid(vector<string> &board, int x, int y) {
        // cout << "checking " << x << " and " << y << endl;
        int n = board.size();
        // check up, left up, right up
        for (int i = 1; i <= x; ++i) {
            if (board[x - i][y] != '.') {
                // cout << "invalid in up" << endl;
                return false;
            }
        }

        for (int i = 1; i <= x; ++i) {
            if (y - i >= 0 && board[x - i][y - i] != '.') {
                // cout << "invalid in left up" << endl;
                return false;
            }
        }

        for (int i = 1; i <= x; ++i) {
            if (y + i < n && board[x - i][y + i] != '.') {
                // cout << "invalid in right up" << endl;
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    s.solveNQueens(5);

    return 0;
}