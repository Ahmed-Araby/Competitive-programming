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
    TreeNode* build_max_tree(TreeNode *root, int &sum)
    {
        if(root==0)
            return 0;
        
        TreeNode *newRoot = new TreeNode();
        newRoot->right = build_max_tree(root->right, sum);
        sum += root->val;
        newRoot->val = sum;
        newRoot->left = build_max_tree(root->left, sum);
        return newRoot;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode *newRoot = build_max_tree(root, sum);
        return newRoot;
        
    }
};
