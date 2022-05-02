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
        int A = 0, B = 0, C = 0;
        for (int i = 0; i < total; ++i) {
            if ((a >= b && a >= c && A != 2) || (a > 0 && B == 2) ||
                (a > 0 && C == 2)) {
                answer += 'a';
                A++;
                a--;
                B = 0, C = 0;
            } else if ((b >= a && b >= c && B != 2) || (b > 0 && A == 2) ||
                       (b > 0 && C == 2)) {
                answer += 'b';
                B++;
                b--;
                A = 0, C = 0;
            } else if ((c >= b && c >= a && C != 2) || (c > 0 && A == 2) ||
                       (c > 0 && B == 2)) {
                answer += 'c';
                C++;
                c--;
                B = 0, A = 0;
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    int a = 2, b = 4, c = 1;
    string answer = s.longestDiverseString(a, b, c);
    cout << answer << endl;
    return 0;
}