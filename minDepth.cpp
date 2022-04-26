#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <queue>
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
    int minDepth_DFS(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = minDepth_DFS(root->left);
        int right = minDepth_DFS(root->right);

        if (left == 0) {
            return 1 + right;
        } else if (right == 0) {
            return 1 + left;
        } else {
            return min(left, right) + 1;
        }
    }

    int minDepth_BFS(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int minimun = 1;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int cnt = q.size();

            // once a layer
            while (cnt > 0) {
                TreeNode *tmp = q.front();
                q.pop();

                if (!tmp->left && !tmp->right) {
                    return minimun;
                }

                if (tmp->left) {
                    q.push(tmp->left);
                }

                if (tmp->right) {
                    q.push(tmp->right);
                }

                cnt--;
            }

            minimun++;
        }
        return minimun;
    }
};

int main() {
    Solution s;

    return 0;
}