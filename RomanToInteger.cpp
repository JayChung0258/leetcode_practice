#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        int answer = 0;
        initAlphabet();
        for (int i = 0; i < s.length() - 1; ++i) {
            if (alphabet[s[i]] < alphabet[s[i + 1]]) {  // ex: CM XC
                answer -= alphabet[s[i]];
            } else {
                answer += alphabet[s[i]];
            }
        }

        return answer + alphabet[s.back()];
    }

   private:
    unordered_map<char, int> alphabet;
    void initAlphabet() {
        alphabet = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                    {'C', 100}, {'D', 500}, {'M', 1000}};
    };
};

int main() {
    Solution s;
    string c = "MCMXCIV";
    int answer = s.romanToInt(c);
    cout << answer << endl;
    return 0;
}