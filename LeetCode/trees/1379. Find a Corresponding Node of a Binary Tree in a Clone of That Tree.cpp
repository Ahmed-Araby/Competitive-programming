/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    /*
    bool dfs1(TreeNode *ref , vector<bool> &inst, TreeNode *target)
    {
        // base case
        if(ref==target) // compare the referecne (address)
        {
            return 1;
        }
        
        if(ref->left!=NULL)
        {
            inst.push_back(0);
            if(dfs1(ref->left, inst, target))
                return 1;
            inst.pop_back();
        }
        
        if(ref->right!=NULL)
        {
            inst.push_back(1);
            if(dfs1(ref->right, inst, target))
                return 1;
            inst.pop_back();
        }
        return 0;
    }
        
        
    TreeNode* dfs2(TreeNode *ref, vector<bool> &inst)
    {
        // base case 
        if(inst.empty())
        {
            return ref; // reference to the required node in the cloned tree.
        }
        
        if(inst.back()==1)
        {
            inst.pop_back();
            return dfs2(ref->right, inst);
        }
        
        else{
            inst.pop_back();
            return dfs2(ref->left , inst);
        }
        return NULL;  // will never happen
    }
      */  
    
    
    TreeNode * traverse_tree(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==target)
            return cloned;
        
        if(original->left!=NULL)
        {
            TreeNode *tmp = traverse_tree(original->left , cloned->left, target);
            if(tmp!=NULL)
                return tmp;
        }
        
        if(original->right!=NULL){
            TreeNode *tmp = traverse_tree(original->right, cloned->right, target);
            if(tmp!=NULL)
                return tmp;
        }
        return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        /*
        // get the path to the reference in terms of left , right 
        // using dfs
        // stupid solution
        vector<bool> inst;
        dfs1(original, inst, target);
        
        reverse(inst.begin(), inst.end());
        TreeNode * cloned_ref = dfs2(cloned, inst);
        return cloned_ref; */
    
        // smarter solution : traverse the two trees togeather 
        return traverse_tree(original , cloned, target);
    }
};
