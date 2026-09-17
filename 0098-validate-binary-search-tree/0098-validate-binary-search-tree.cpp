/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool solve(TreeNode* &root, long minVal, long maxVal) {
        // base case
        if(root == nullptr)
            return true;
        // recursive relation
        if(root->val <= minVal || maxVal <= root->val)
            return false;
        bool left = solve(root->left, minVal, root->val);
        bool right = solve(root->right, root->val, maxVal);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};