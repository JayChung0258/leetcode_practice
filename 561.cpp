#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 0;
        for (int i = 0; i < nums.size(); i = i + 2) {
            answer += nums[i];
        }
        return answer;
    }
};

int main() {
    Solution s;

    return 0;
}