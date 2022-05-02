#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string answer = "";
        int total = a + b + c;
        map<char, int> m = {{'a', a}, {'b', b}, {'c', c}};
        vector<int> ve = {a, b, c};

        for (int i = 0; i < total; ++i) {
            addMaxChar(answer, m, ve);
        }

        return answer;
    }

   private:
    void addMaxChar(string &answer, map<char, int> &m, vector<int> &ve) {
        // find max value of map
        sort(ve.begin(), ve.end());
        int maxValue = ve.back();
        char maxChar;
        char anotherChar;

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == maxValue) {
                maxChar = it->first;
            }
        }

        cout << "maxChar: " << maxChar << endl;

        if (answer.size() < 2) {
            answer += maxChar;
            ve[ve.size() - 1]--;
            m[maxChar]--;
            return;
        }

        // check if max char can be put in
        if (answer[answer.size() - 1] == maxChar &&
            answer[answer.size() - 2] == maxChar) {
            // duplicate, find another
            cout << "cant put in" << endl;
            if (ve[1] > 0) {
                maxValue = ve[1];
                for (auto it = m.begin(); it != m.end(); ++it) {
                    if (it->second == maxValue && maxChar != it->first) {
                        anotherChar = it->first;
                    }
                }

                cout << "find another: " << anotherChar << endl;

                answer += anotherChar;
                ve[1]--;
                m[anotherChar]--;
            } else {
                return;
            }
        } else {
            cout << "can put in" << endl;
            answer += maxChar;
            ve[ve.size() - 1]--;
            m[maxChar]--;
        }

        cout << endl;
    }
};

int main() {
    Solution s;
    int a = 2, b = 4, c = 1;
    string answer = s.longestDiverseString(a, b, c);
    cout << answer << endl;
    return 0;
}