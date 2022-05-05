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
 //TC: O(N)
 //SC: O(h) where h = height of binary tree as at most "h" number of elements will be at stack at any given point
class Solution {
public:
    void inorderHelper(TreeNode* node, vector<int>& result)
    {
        if(node == nullptr)
            return;
        
        inorderHelper(node->left, result);
        result.push_back(node->val);        
        inorderHelper(node->right, result);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        inorderHelper(root, result);
        
        return result;
        
    }
};
