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
    int calcSubTreeSum(TreeNode *root, map<int, int> &freq)
    {
        if(root == nullptr)
            return 0;
        
        int sum = 0;
        sum +=calcSubTreeSum(root->left, freq);
        sum +=calcSubTreeSum(root->right, freq);
        sum +=root->val;
        
        freq[sum] +=1;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> freq ;
        
        calcSubTreeSum(root, freq);
        map<int, int> ::iterator itr = freq.begin();
        int maxi = 0;
        
        for(; itr!=freq.end(); itr++)
            maxi = max(maxi, itr->second);
        
        //cout<<maxi<< endl;
        
        vector<int> res;
        for(itr=freq.begin(); itr!=freq.end(); itr++)
            if(itr->second == maxi)
                res.push_back(itr->first);
        
        return res;
    }
};
