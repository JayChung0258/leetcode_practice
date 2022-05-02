#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int answer = 1;
        for (auto i : nums) {
            if (i == 0) {
                return 0;
            } else if (i > 0) {
                answer *= 1;
            } else {
                answer *= -1;
            }
        }

        return answer;
    }
};

int main() {
    Solution s;

    return 0;
}