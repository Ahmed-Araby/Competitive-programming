/*
serializating in the same way 
leet code does
but this would cuz TLE in case of 1 sided heavy tree
not blanced at all --- > look like linear array
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string to_string(int num)
    {
        stringstream cvt;
        cvt << num;
        string s;
        cvt >> s;
        return s;
    }
    
    int to_int(string s)
    {
        stringstream cvt (s);
        int num =0;
        cvt >> num;
        return num;
    }
    
    void str_split(string s, char dlim, vector<string> &v)
    {
        string tmp = "";
        // avoid [ and ]
        for(int i=1; i<s.size()-1; i++)
        {
            if(s[i]== dlim)
            {
                v.push_back(tmp);
                tmp = "";
            }
            else 
                tmp +=s[i];
        }
        if(tmp!="")
            v.push_back(tmp);
        return ;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        // this solution is so stupid 
        // in case of sided heavy tree
        
        vector<string> v;
        int notNull = 0;
        if(root!=nullptr){
            v.push_back(to_string(root->val));
            notNull +=1;
        }
        
        /*
        apply bfs to searialize
        it like leetcode 
        */

        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty() && notNull > 0)
        {
            root = q.front();
            q.pop();
            if(root == nullptr){
                TreeNode * tmp = nullptr;
                q.push(tmp);
                q.push(tmp);
                v.push_back("null");
                v.push_back("null");
            }
            else{
                notNull -=1;
                
                q.push(root->left);
                q.push(root->right);
                if(root->left !=nullptr){
                    notNull +=1;
                    v.push_back(to_string(root->left->val));
                }
                else 
                    v.push_back("null");
                if(root->right !=nullptr){
                    notNull +=1;
                    v.push_back(to_string(root->right->val));
                }
                else 
                    v.push_back("null");
            }
        }
        
        // remove the nulls in the end
        // 2 nulls at most
        while(!v.empty() && 
              v.back() == "null")
            v.pop_back();
        
        
        // build the string 
        string str = "[";
        for(int i=0; i<v.size(); i++)
        {
            str +=v[i];
            if(i+1!=v.size())
                str +=",";
        }
        str +="]";
        
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /*
        build a node for each not null entry 
        */
        if(data == "[]")
            return nullptr;
        
        vector<string> v;
        str_split(data, ',', v);
        
        vector<TreeNode *> ref(v.size());
        ref[0] = nullptr;
        if(v.size() > 0 && v[0] !="null"){
         ref[0] = new TreeNode();  
         ref[0]->val = to_int(v[0]);
        }
        
        int p = 0, c=1;
        while(c<v.size())
        {
            if(v[c]!="null"){
                ref[c] = new TreeNode();
                ref[c]->val= to_int(v[c]);
                ref[p]->left = ref[c];
            }
            if(c+1 <v.size() && v[c+1] !="null"){
                ref[c+1] = new TreeNode();
                ref[c+1]->val = to_int(v[c+1]);
                ref[p]->right = ref[c+1];
            }
            c +=2;
            p+=1;
        }
        return ref[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
