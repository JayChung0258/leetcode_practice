#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        // row[i] ->  nums of services in i th row
        // col[i] -> nums of services in i th column
        int answer = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    answer++;
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution s;

    return 0;
}