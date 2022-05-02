#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string s;

        dfs(n, n, s, answer);

        return answer;
    }

   private:
    void dfs(int left, int right, string &s, vector<string> &answer) {
        // cout << s << endl;
        // terminate
        if (left == 0 && right == 0) {
            answer.push_back(s);
        }

        if (left > right || left < 0 || right < 0) {
            // wrong
            return;
        }

        s.push_back('(');
        dfs(left - 1, right, s, answer);
        s.pop_back();

        s.push_back(')');
        dfs(left, right - 1, s, answer);
        s.pop_back();
    }
};

int main() {
    Solution s;

    vector<string> answer = s.generateParenthesis(3);

    for (auto i : answer) {
        cout << i << endl;
    }

    return 0;
}