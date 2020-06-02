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
    int get_value(int &i, string &s)
    {
        int num = 0;
        while(i<s.size() && s[i]!='-')
            num = num*10 + s[i++]-'0';
        return num;
    }
    TreeNode* recoverFromPreorder(string S) {
        
        /*
        it looks like we need to build a parser.
        */
        
        // preorder traversal 
        // parent, left , right and so on 
        // no need for recursive simulation 
        
        int n = S.size();
        // dynamicallt allocated array of TreeNode pointers
        // we need to be curicial about referencing the same nodes all the time 
        // using pointers 
        
        TreeNode **depth = new TreeNode*[n+2];
        TreeNode *root;
        
        int i=0, dep=0;
        while(i<n)
        {
            // start of tree value
            if(S[i]!='-')
            {
                int val = get_value(i, S); // i will be changed as it's passed by reference
                // place it
                if(dep==0){
                    root = new TreeNode(val);
                    depth[dep] = root;
                }
                else{
                    TreeNode * tmpNode = new TreeNode(val);
                    
                    if(depth[dep-1]->left==nullptr)
                        depth[dep-1]->left = tmpNode;
                    else 
                        depth[dep-1]->right = tmpNode;
                    depth[dep] = tmpNode;
                }
                dep = 0;
            }
            else{
                dep+=1;
                i+=1;
            }
        }
        
        return root;
    }
};
