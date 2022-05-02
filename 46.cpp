#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> ele = {};

        per(nums, ele, answer);

        return answer;
    }

   private:
    void per(vector<int> nums, vector<int> ele, vector<vector<int>>& answer) {
        if (nums.size() == 0) {
            // permutation done
            answer.push_back(ele);
        }
        for (int i = 0; i < nums.size(); ++i) {
            ele.push_back(nums[i]);
            vector<int> tmp = nums;
            tmp.erase(tmp.begin() + i);
            per(tmp, ele, answer);
            ele.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer;

    answer = s.permute(nums);

    for (auto i : answer) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}