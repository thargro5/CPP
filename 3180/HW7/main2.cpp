#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) {
        return true; // Both subtrees are empty, so they are symmetric.
    }
    if (left == nullptr || right == nullptr) {
        return false; // One of the subtrees is empty, so they are not symmetric.
    }
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true; // An empty tree is considered symmetric.
    }
    return isMirror(root->left, root->right);
}
int main() {
// Test 1
    TreeNode t1(15); // leaf
    TreeNode t2(15); // leaf
    TreeNode t3(15); // leaf
    TreeNode t4(15);
    TreeNode t5(20, &t1, &t2); // internal node
    TreeNode t6(20, &t3, &t4); // internal node
    TreeNode t7(1, &t5, &t6); // root
    cout << "Test 1: " <<(isSymmetric(&t7) ? "true" : "false")<< endl; // 3
// Test 2
    TreeNode n4(4, nullptr, nullptr); // leaf
    TreeNode n3(3, nullptr, &n4); // internal node
    TreeNode n2(2, &n3, nullptr); // internal node
    TreeNode n1(1, nullptr, &n2); // root
    cout << "Test 2: "<<(isSymmetric(&n1) ? "true" : "false") << endl; // 4
    
// Test 3 
    TreeNode s1(1, nullptr, nullptr);//root
    cout << "Test 3: "<<(isSymmetric(&s1) ? "true" : "false") << endl;
    
    return 0;
}
