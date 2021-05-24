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
    void in_order_dfs(TreeNode* root, vector<int> &nodes)
    {
        if(root==0)
            return ;
        in_order_dfs(root->left, nodes);
        nodes.push_back(root->val);
        in_order_dfs(root->right, nodes);
        return ;
    }
    
    vector<int> merge(vector<int> &v1, vector<int> &v2)
    {
        int index1 = 0, index2 = 0;
        int n1 = v1.size(), n2 = v2.size();
        vector<int> ans;
        
        while(index1 < n1 || index2 < n2)
        {
            if(index1 < n1 && index2 < n2){
                if(v1[index1] <= v2[index2])
                    ans.push_back(v1[index1++]);
                else 
                    ans.push_back(v2[index2++]);
            }
            else if(index1 < n1)
                ans.push_back(v1[index1++]);
            else
                ans.push_back(v2[index2++]);
        }
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        in_order_dfs(root1, v1);
        in_order_dfs(root2, v2);
        return merge(v1, v2);
    }
};
