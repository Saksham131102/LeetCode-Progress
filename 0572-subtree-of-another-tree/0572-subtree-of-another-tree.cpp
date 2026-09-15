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
    bool sameTree(TreeNode* &p, TreeNode* &q) {
        // base case
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr && q != nullptr || p != nullptr && q == nullptr)
            return false;
        if(p->val != q->val)
            return false;
        
        // recursive relation
        bool left = sameTree(p->left, q->left);
        bool right = sameTree(p->right, q->right);
        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)
            return false;
        
        if(root->val == subRoot->val && sameTree(root, subRoot))
            return true;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};