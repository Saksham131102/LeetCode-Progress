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
    TreeNode* _deleteNode(TreeNode* &root) {
        TreeNode* right_node = root->right;
        TreeNode* left_node = root->left;
        if(right_node == nullptr)
            return left_node;
        root->right = nullptr;
        TreeNode* temp = right_node;
        while(temp->left != nullptr)
            temp = temp->left;
        temp->left = left_node;
        return right_node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(key == root->val)
            return _deleteNode(root);
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};