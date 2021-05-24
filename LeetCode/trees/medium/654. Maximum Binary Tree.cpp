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
    int getMaxIndex(int l, int r, vector<int> &nums)
    {
        int mIndex = -1;
        for(; l<=r; l++)
            if(mIndex == -1 || nums[mIndex] < nums[l])
                mIndex = l;
        return mIndex;
    }
    
    TreeNode *build_max_b_tree(int l, int r, vector<int>& nums)
    {
        if(l>r)
            return 0;
        
        int mIndex = getMaxIndex(l, r, nums);
        TreeNode * node = new TreeNode();
        node->val = nums[mIndex];
        node->left = build_max_b_tree(l, mIndex-1, nums);
        node->right = build_max_b_tree(mIndex+1, r, nums);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build_max_b_tree(0, nums.size()-1, nums);
    }
};
