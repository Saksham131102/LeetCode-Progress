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
    pair<int, int> solve(TreeNode* &root) {
        // base case
        if(root == nullptr)
            return {0, 0};
        // recursive relation
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        int rob = root->val + left.second + right.second;
        int notRob = 0 + max(left.first, left.second) + max(right.first, right.second);
        return {rob, notRob};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> p = solve(root);
        int rob = p.first;
        int notRob = p.second;
        return max(rob, notRob);
    }
};