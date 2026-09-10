/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;give 
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, int> dfs(TreeNode* root, int& count) {
        if (!root) return {0, 0};

        auto [leftSum, leftNodes] = dfs(root->left, count);
        auto [rightSum, rightNodes] = dfs(root->right, count);

        int sum = leftSum + rightSum + root->val;
        int nodes = leftNodes + rightNodes + 1;

        if (root->val == sum / nodes) {
            count++;
        }

        return {sum, nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};