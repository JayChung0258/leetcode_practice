#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<char, int> m;

    m['a']--;

    cout << m['a'] << endl;
    cout << m.size() << endl;

    return 0;
}