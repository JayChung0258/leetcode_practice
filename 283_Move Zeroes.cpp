#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int pointer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (pointer != i) {
                    nums[pointer] = nums[i];
                    nums[i] = 0;
                }
                pointer++;
            }
        }
    }
};

int main() {
    Solution s;
    // 0 1 0 3 2 => 1 0 0 3 2 => 1 3 0 0 2 => 1 3 2 0 0
    // 1 1 0 2 2 0 3 3 => 1 1 2 0 2 0 3 3 => 1 1 2 2 0 0 3 3 => 1 1 2 2 3 0 3 0
    // => 1 1 2 2 3 3 0 0 1 1 0 0 2 1 => 1 1 2 0 0 1 => 1 1 2 1 0 0
    vector<int> nums = {0, 0, 1};
    s.moveZeroes(nums);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}