#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> stack;

        for (auto i : s) {
            if (i == '(' || i == '[' || i == '{') {
                stack.push(i);
            } else {
                if (stack.empty() || (i == ')' && stack.top() != '(') ||
                    (i == ']' && stack.top() != '[') ||
                    (i == '}' && stack.top() != '{')) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};

int main() {
    Solution s;

    bool answer = s.isValid("()[]]");

    stack<char> stack;
    cout << stack.top() << endl;

    cout << answer << endl;

    return 0;
}