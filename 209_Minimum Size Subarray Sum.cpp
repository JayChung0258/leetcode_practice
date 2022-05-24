#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = INT16_MAX;
        int windowStart = 0, windowEnd = 0;
        int n = nums.size();

        int ret = 0;

        while (windowEnd < n) {
            cout << "windowStart: " << windowStart
                 << " windowEnd: " << windowEnd << endl;
            // if (ret == target) {
            //     // find one solution
            //     answer = min(answer, windowEnd - windowStart);
            //     cout << "answer: " << answer << endl;
            //     ret -= nums[windowStart];
            //     windowStart++;
            // } else if (ret < target) {
            //     ret += nums[windowEnd];
            //     windowEnd++;
            // } else {
            //     // ret > target
            //     ret -= nums[windowStart];
            //     windowStart++;
            // }

            ret += nums[windowEnd];

            while (ret >= target) {
                // scale down window
                answer = min(answer, windowEnd - windowStart + 1);
                ret -= nums[windowStart];
                windowStart++;
            }

            windowEnd++;

            cout << "ret: " << ret << endl;
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    int answer = s.minSubArrayLen(7, nums);
    cout << answer << endl;

    return 0;
}