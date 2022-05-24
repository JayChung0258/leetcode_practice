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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> answer;
        inorder(root, answer);
        return answer;
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> answer;
        postorder(root, answer);
        return answer;
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> answer;
        preorder(root, answer);
        return answer;
    }

   private:
    void inorder(TreeNode *root, vector<int> &answer) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
    }

    void postorder(TreeNode *root, vector<int> &answer) {
        if (root == nullptr) {
            return;
        }

        postorder(root->left, answer);
        postorder(root->right, answer);
        answer.push_back(root->val);
    }

    void preorder(TreeNode *root, vector<int> &answer) {
        if (root == nullptr) {
            return;
        }

        answer.push_back(root->val);
        preorder(root->left, answer);
        preorder(root->right, answer);
    }
};

int main() {
    Solution s;

    return 0;
}