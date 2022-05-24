#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        int windowStart = 0, windowEnd = 0;
        unordered_map<char, int> freq_m;
        unordered_map<char, int> freq_t;

        string answer;
        int length = INT32_MAX;
        int count = 0;

        for (auto i : t) {
            freq_t[i]++;
        }

        for (windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            // check if now t in s
            if (freq_t[s[windowEnd]] > 0 &&
                freq_t[s[windowEnd]] > freq_m[s[windowEnd]]) {
                count++;
            }
            // append end
            freq_m[s[windowEnd]]++;

            if (count == t.size()) {
                // cut
                while (windowStart < windowEnd &&
                       (freq_t[s[windowStart]] == 0 ||
                        freq_t[s[windowStart]] < freq_m[s[windowStart]])) {
                    if (freq_t[s[windowStart]] < freq_m[s[windowStart]]) {
                        freq_m[s[windowStart]]--;
                    }
                    windowStart++;
                }

                if (windowEnd - windowStart + 1 < length) {
                    answer = s.substr(windowStart, windowEnd - windowStart + 1);
                    length = windowEnd - windowStart + 1;
                }
            }
        }

        if (length == INT32_MAX) {
            return "";
        }

        return answer;
    }
};

int main() {
    Solution s;

    string str = "ADOBECODEBANC";
    string t = "ABC";

    string answer = s.minWindow(str, t);

    cout << answer << endl;

    return 0;
}