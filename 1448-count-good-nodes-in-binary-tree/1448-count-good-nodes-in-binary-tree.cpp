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
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        if(root == nullptr)
            return cnt;
        int maxVal = INT_MIN;
        queue<pair<int, TreeNode*>> q;
        q.push({maxVal, root});

        while(!q.empty()) {
            auto [maxVal, node] = q.front();
            q.pop();
            int nodeVal = node->val;
            if(nodeVal >= maxVal)
                cnt++;
            maxVal = max(maxVal, nodeVal);
            if(node->left != nullptr)
                q.push({maxVal, node->left});
            if(node->right != nullptr)
                q.push({maxVal, node->right});
        }

        return cnt;
    }
};