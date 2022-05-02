#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumDeletions(string s) {
        int answer = INT32_MAX;

        vector<int> pre(s.size());  // pre[5] -> 5 之前 b的數量
        pre[0] = s[0] == 'b';
        for (int i = 0; i < s.size() - 1; i++) {
            pre[i + 1] = pre[i] + (s[i + 1] == 'b');  // recursion
        }

        vector<int> suf(s.size());
        suf[s.size() - 1] = s.back() == 'a';
        for (int i = s.size() - 1; i > 0; i--) {
            suf[i - 1] = suf[i] + (s[i - 1] == 'a');
        }

        answer = min(pre[s.size() - 1], suf[0]);
        for (int i = 0; i < s.size() - 1; ++i) {
            answer = min(answer, pre[i] + suf[i + 1]);
        }

        return answer;

        // answer = prfixA(i) + suffixB(i)
    }
};

int main() {
    Solution s;
    string str = "ababbaaababbba";

    int answer = s.minimumDeletions(str);

    cout << answer << endl;
    return 0;
}