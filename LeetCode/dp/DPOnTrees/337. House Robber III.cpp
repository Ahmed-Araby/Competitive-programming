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
    // very simple dp on trees
    
    int dfs(TreeNode *ref, bool rop , map< pair<TreeNode *, bool>, int> &dp)
    {
        if(ref==NULL)
            return 0;
        
        int &ret = dp[{ref, rop}];
        if(ret!=0)
            return max(0, ret);
        
        if(rop)
        {
            ret = ref->val;
            ret+=dfs(ref->left, 0, dp);
            ret +=dfs(ref->right, 0, dp);
        }
        
        if(rop==0)
            rop=1;
        int l =0 , r=0;
        l = dfs(ref->left , 1, dp);
        r = dfs(ref->right, 1, dp);
        cout<<ret<<" "<<l+r<< endl;
        ret = max(ret, l+r);
        if(ret==0)
            ret = -1;
        return   max(0 , ret);  // return ret was my bug !!!! as -1 was added to the sol !!!
    }
    
    int rob(TreeNode* root) {
        // if No child of URS is roped
        // so U can be roped 
        // dfs, bfs  could be used 
        map< pair<TreeNode*, bool>, int > dp;
        return dfs(root, 1, dp);
    }
};
