#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *answer = nullptr;
        while (root) {
            if (root->val > p->val) {
                // go left
                answer = root;
                root = root->left;
            } else {
                // go righ
                root = root->right;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;

    return 0;
}