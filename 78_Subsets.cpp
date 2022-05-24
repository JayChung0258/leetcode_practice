#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> blank = {};
        vector<vector<int>> answer;

        answer.push_back(blank);

        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i], answer);
        }

        return answer;
    }

   private:
    void add(int number, vector<vector<int>>& answer) {
        int n = answer.size();
        for (int i = 0; i < n; ++i) {
            vector<int> tmp = answer[i];
            tmp.push_back(number);
            answer.push_back(tmp);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> answer;

    answer = s.subsets(nums);

    for (auto i : answer) {
        for (auto j : i) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}