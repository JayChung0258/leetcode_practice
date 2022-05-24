#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int majaority = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[majaority] == nums[i]) {
                counter++;
            } else if (nums[majaority] != nums[i]) {
                counter--;
            }
            if (counter < 0) {
                majaority = i;
                counter = 0;
            }
        }
        return nums[majaority];
    }
};

int main() {
    Solution s;

    return 0;
}