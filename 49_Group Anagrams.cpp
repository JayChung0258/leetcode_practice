#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(tmp);
        }

        vector<vector<string>> answer;
        for (auto i : m) {
            answer.push_back(i.second);
        }

        return answer;
    }
};

int main() {
    Solution s;

    return 0;
}