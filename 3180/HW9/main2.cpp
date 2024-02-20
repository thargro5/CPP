#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2; // Avoid integer overflow
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);

        return root;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    std::cout << root->val << " "<<'\n';
    printTree(root->right);
}

int main() {
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);
    printTree(root);
    return 0;
}
