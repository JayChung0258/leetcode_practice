#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";

        int j = 0;
        while (strs[0][j]) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] != strs[0][j]) {
                    return answer;
                }
            }
            answer += strs[0][j];
            j++;
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    string answer = s.longestCommonPrefix(strs);
    cout << answer << endl;
    return 0;
}