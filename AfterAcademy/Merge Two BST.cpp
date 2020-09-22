/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * @type of bst1: TreeNode
 * @type of bst2: TreeNode
 * @return type: integer array
 */

class Solution {
public:
    vector<int> mergeTwoBST(TreeNode* bst1, TreeNode* bst2) {
   		// write your awesome code here
        // okay
        
        /*
        pointer to the last node in traversal 
        and state of the node 
        0 get left 
        1 compare ur self and push right
        
        after getting right pop ur self
        */
        
        stack<pair<TreeNode *, int> > s1 , s2;
        
       	if(bst1!=NULL)
            s1.push({bst1, 0});
        if(bst2!=NULL)
            s2.push({bst2, 0});
                    
        TreeNode * tmpNode = new TreeNode(INT_MAX);
        vector<int> res;
                    
        while(!s1.empty() || !s2.empty())
        {
            pair<TreeNode*, int> top1, top2;
         	
            if(s1.empty() == false){
            	top1 = s1.top();
                s1.pop();
            }
            else{
                top1 = {tmpNode,  2};
            }
            
            if(!s2.empty()){
                top2 = s2.top();
                s2.pop();
            }
            else{
                top2 = {tmpNode, 2};
            }
            
            if(top1.second != 0 && top2.second != 0)
            {
                // compare
                if(top1.first->val <= top2.first->val){
                    res.push_back(top1.first->val);
                    if(top1.first->right !=NULL)
                        s1.push({top1.first->right, 0});
                   	if(top2.second !=2)
                    	s2.push(top2);
                }
                else{
                    res.push_back(top2.first->val);
              		if(top2.first->right !=NULL)
                        s2.push({top2.first->right, 0}); 
                   	if(top1.second !=2)
                    	s1.push(top1);
                }
            }
            else{
                if(top1.second == 0){
                    top1.second = 1;
                    s1.push(top1);
                    if(top1.first->left !=NULL)
                        s1.push({top1.first->left, 0});
                }
                
                else
                    s1.push(top1);
                
                if(top2.second == 0){
                    top2.second = 1;
                    s2.push(top2);
                    if(top2.first->left !=NULL)
                        s2.push({top2.first->left, 0});
                } 
                else
                    s2.push(top2);
            }
        }        
        return res;
    }
};
