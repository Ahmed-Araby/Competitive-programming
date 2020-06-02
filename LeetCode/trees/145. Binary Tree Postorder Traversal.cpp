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
    vector<int> postorderTraversal(TreeNode* root) {
        // post order traversal is left , right , parent of left and right 
        // so we will simulate the functin calls with a stack 
        if(root==nullptr)
            return vector<int>();
        
        stack<TreeNode*> s;
        s.push(root);
        vector<int> pot;
        
        while(!s.empty()){
            TreeNode * tmpN = s.top();
            if(tmpN->left == nullptr && tmpN->right == nullptr)
            {
                pot.push_back(tmpN->val);
                s.pop();
            }
            else{
                // put the one to be traversed first on the top
                if(tmpN->right !=nullptr)
                    s.push(tmpN->right);
                if(tmpN->left != nullptr)
                    s.push(tmpN->left); // make a copy of it 
               
                tmpN->left = nullptr; // make the pointer point at nothing 
                tmpN->right = nullptr;
            }
        }
        return pot;
    }
};
