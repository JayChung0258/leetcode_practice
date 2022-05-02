#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }

        int answer = -9999;
        int windowStart = 0, windowEnd = 0;
        string ret;
        unordered_map<char, int> m;

        for (int windowEnd = 0; windowEnd < s.size(); ++windowEnd) {
            ret += s[windowEnd];
            m[s[windowEnd]]++;
            while (m.size() > k) {
                // delete from windowStart
                m[s[windowStart]]--;
                if (m[s[windowStart]] == 0) {
                    m.erase(s[windowStart]);
                }
                windowStart++;
            }
            answer = max(answer, windowEnd - windowStart + 1);
        }

        return answer;
    }
};

int main() {
    Solution s;
    string str = "kjdsssskkkjsdlfkjsd";
    int k = 2;

    int answer = s.lengthOfLongestSubstringKDistinct(str, k);
    cout << answer << endl;

    return 0;
}