#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int answer = 0;

        // input and tidy the reserved seats with map
        unordered_map<int, vector<int>> booked;
        for (auto reserved : reservedSeats) {
            booked[reserved[0]].push_back(reserved[1]);
        }

        // no booked row can sit by 2 families
        answer += (n - booked.size()) * 2;

        for (auto row : booked) {
            int left_free = 1;
            int right_free = 1;
            int middle_free = 1;

            // check left and right
            for (auto reservedNum : row.second) {
                if (reservedNum >= 2 && reservedNum <= 5) {
                    left_free = 0;
                }
                if (reservedNum <= 9 && reservedNum >= 6) {
                    right_free = 0;
                }
                if (reservedNum >= 4 && reservedNum <= 7) {
                    middle_free = 0;
                }
            }
            if (left_free && right_free) {
                answer += 2;
            } else if (left_free || right_free || middle_free) {
                answer++;
            }
        }

        return answer;
    }
};

int main() {
    Solution s;

    int n = 4;
    vector<vector<int>> reservedSeats = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};

    int answer = s.maxNumberOfFamilies(n, reservedSeats);

    cout << answer << endl;

    return 0;
}