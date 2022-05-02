#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sumZero(int n) {
        vector<int> answer;
        int bound = n / 2;

        for (int i = -bound; i < bound + 1; ++i) {
            if (i == 0) {
                continue;
            } else {
                answer.push_back(i);
            }
        }

        if (n % 2 == 1) {
            answer.push_back(0);
        }

        return answer;
    }
};

int main() {
    Solution s;

    return 0;
}