#include <cmath>

class Solution {
    int totalTilt = 0;

    int calculateSum(TreeNode* node) {
        if (!node) return 0;

        int leftSum = calculateSum(node->left);
        int rightSum = calculateSum(node->right);

        totalTilt += std::abs(leftSum - rightSum);

        return node->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {
        totalTilt = 0;
        calculateSum(root);
        return totalTilt;
    }
};