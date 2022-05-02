#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        int windowStart = 0, windowEnd = 0;
        int n = s.size();
        set<int> ms = {};

        for (int windowEnd = 0; windowEnd < n; ++windowEnd) {
            while (windowEnd < n) {
                if (ms.find(s[windowEnd]) == ms.end()) {
                    // if can't find, then add it to set
                    ms.insert(s[windowEnd]);

                    windowEnd++;
                } else {
                    // duplicate, move window start till not duplicate
                    ms.erase(s[windowStart]);
                    windowStart++;
                }
            }
        }

        answer = max(answer, int(ms.size()));

        return answer;
    }
};

int main() {
    Solution s;
    string str = "abcabcbb";

    string t = " ";
    cout << t.size() << endl;

    int answer = s.lengthOfLongestSubstring(str);
    cout << answer << endl;

    return 0;
}