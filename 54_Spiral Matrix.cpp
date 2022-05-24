#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;

        search(0, 0, 0, matrix, answer);
        return answer;
    }

   private:
    void search(int x, int y, int direction, vector<vector<int>>& matrix,
                vector<int>& answer) {
        int bandwidth = matrix[0].size(), height = matrix.size();
        int i = 1;

        cout << bandwidth << height << endl;
        cout << "now: " << x << " " << y << endl;

        if (x >= height || x < 0 || y >= bandwidth || y < 0) {
            return;
        }

        if (matrix[x][y] == INT16_MAX) {
            return;
        }

        answer.push_back(matrix[x][y]);
        matrix[x][y] = INT16_MAX;

        switch (direction % 4) {
            case 0:
                // right
                while (y + i < bandwidth && matrix[x][y + i] != INT16_MAX) {
                    answer.push_back(matrix[x][y + i]);
                    matrix[x][y + i] = INT16_MAX;
                    ++i;
                }

                search(x + 1, y + i - 1, direction + 1, matrix, answer);
                break;

            case 1:
                // down

                while (x + i < height && matrix[x + i][y] != INT16_MAX) {
                    answer.push_back(matrix[x + i][y]);
                    matrix[x + i][y] = INT16_MAX;
                    ++i;
                }

                search(x + i - 1, y - 1, direction + 1, matrix, answer);

                break;
            case 2:
                // left

                while (y - i >= 0 && matrix[x][y - i] != INT16_MAX) {
                    answer.push_back(matrix[x][y - i]);
                    matrix[x][y - i] = INT16_MAX;
                    ++i;
                }

                search(x - 1, y - i + 1, direction + 1, matrix, answer);

                break;
            case 3:
                // up

                while (x - i >= 0 && matrix[x - i][y] != INT16_MAX) {
                    answer.push_back(matrix[x - i][y]);
                    matrix[x - i][y] = INT16_MAX;
                    ++i;
                }

                search(x - i + 1, y + 1, direction + 1, matrix, answer);

                break;
            default:
                break;
        }
    }
};

int main() {
    Solution s;
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // vector<vector<int>> matrix = {{1, 2}};

    vector<int> answer = s.spiralOrder(matrix);

    for (auto i : answer) {
        cout << i << " ";
    }
    return 0;
}