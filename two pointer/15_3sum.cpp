#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answerList;

        sort(nums.begin(), nums.end());

        int i;

        for (i = 0; i < nums.size(); i++) {
            cout << i << endl;
            int target = -nums[i];
            int low = i + 1, high = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while (low < high) {
                cout << "low: " << low << endl;
                cout << "high: " << high << endl;
                if (nums[low] + nums[high] == target) {
                    // push
                    vector<int> tmp = {nums[i], nums[low], nums[high]};
                    answerList.push_back(tmp);

                    while (low < high && nums[low] == nums[low + 1]) {
                        low++;
                    }

                    while (low < high && nums[high] == nums[high - 1]) {
                        high--;
                    }

                    low++;
                    high--;

                } else if (nums[low] + nums[high] < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return answerList;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};  // -4 -1 -1 0 1 2
    vector<vector<int>> answer = {};

    Solution s;
    answer = s.threeSum(nums);

    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            cout << answer[i][j];
        }
        cout << "\n";
    }

    return 0;
}