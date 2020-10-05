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




/*
this solution is mine 
and it's idea is based on just searialize nodes and 
save with them the index of where the parent is exist in the serialization
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

#define pi pair<int ,int>
/*string to_string(int num)
{
    stringstream cvt;
    cvt << num;
    string s;
    cvt >> s;
    return s;
}*/

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
    
struct node 
{
    int pId;
    bool pos;
    int val;
    node(){}
    node(int _pId, int _pos, int _val)
    {
        pId = _pId;
        pos = _pos;
        val = _val;
        return ;
    }
    string cvt_to_array()
    {
        /*
        we need to put 
        different kind of delimiter
        */
        
        string tmp ="[";
        tmp += to_string(pId);
        tmp += "*"; 
        tmp +=to_string(pos);
        tmp += "*";
        tmp +=to_string(val);
        tmp +=']';
        return tmp;
    }
};

class Codec {
public:
    void dfs_serialization(TreeNode *root, int pId, bool pos,
                           int& curId, vector<node>& seq)
    {
        if(root==nullptr)
            return ;
        curId +=1;
        
        int curIndex = curId;
        
        node tmpN(pId, pos, root->val);
        seq.push_back(tmpN);
        dfs_serialization(root->left, curIndex, 0,  curId, seq);
        dfs_serialization(root->right, curIndex, 1, curId, seq);
        return ;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {  
        int curId = -1;
        vector<node> v;
        dfs_serialization(root, -1, 0, curId, v);
        
        // build the string 
        string str = "[";
        for(int i=0; i<v.size(); i++)
        {
            str +=v[i].cvt_to_array();
            if(i+1!=v.size())
                str +=",";
        }
        str +="]";
        // array of arrays serialization
        // each inner array contain index of the parent, pos as left or right child,
        // value in the node
        
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /*
        build a node for each not null entry 
        */
        
        if(data == "[]")
            return nullptr;
        
        vector<string> v; // each cell is a string array 
        str_split(data, ',', v);
        
        vector<TreeNode *> ref(v.size());
        // root 
        vector<string> tmpV;   
        str_split(v[0], '*', tmpV);
        ref[0] = new TreeNode();  
        ref[0]->val = to_int(tmpV[2]);
        
        
        int index = 1;
        while(index < v.size())
        {
            tmpV.clear();
            str_split(v[index], '*', tmpV);
            int pId = to_int(tmpV[0]);
            int pos = to_int(tmpV[1]);
            int val = to_int(tmpV[2]);
            
            ref[index] = new TreeNode();
            ref[index]->val = val;
            if(pos == 0)
                ref[pId]->left = ref[index];
            else 
                ref[pId]->right = ref[index];
            index +=1;
        }
        return ref[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
