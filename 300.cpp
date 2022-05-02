#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;

        for (auto i : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), i);
            if (it == dp.end()) {
                // not found -> new
                dp.push_back(i);
            } else {
                *it = i;
            }
        }

        return dp.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int answer = s.lengthOfLIS(nums);

    cout << answer << endl;

    return 0;
}