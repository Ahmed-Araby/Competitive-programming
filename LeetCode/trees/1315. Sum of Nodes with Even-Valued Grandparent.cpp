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

struct elem
{
    TreeNode *curN, *dadN , *grandN;
    elem(){}
    elem(TreeNode *_curN, TreeNode * _dadN, TreeNode * _grandN)
    {
        curN = _curN;
        dadN = _dadN;
        grandN = _grandN;
    }
};
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        
        int sum = 0;
        // do bfs 
        queue<elem> q;
        q.push(elem(root, nullptr, nullptr));
        while(!q.empty())
        {
            TreeNode *curN = q.front().curN, 
            *dadN  = q.front().dadN, *grandN = q.front().grandN;
            
            q.pop();
            if(grandN!=nullptr && grandN->val%2==0)
                sum +=curN->val;
            // explore 
            if(curN->left!=nullptr)
                q.push(elem(curN->left, curN, dadN));
            if(curN->right != nullptr)
                q.push(elem(curN->right, curN, dadN));
        }
        return sum;
    }
};
