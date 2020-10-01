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

#define ll long long

long long modFix(long long a , long long p)
{
    return ((a%p) + p) %p;
}

struct hashTable 
{
    // freq , number 
    list<pair<int, int> > *T;
    int m, a, b;
    ll p;
    hashTable()
    {
        m = 100003;
        p = 1000000007;
        a = rand();
        b = rand();
        T = new list<pair<int, int> > [m];
        return ;
    }
    
    int hashFunction(int value)
    {
        ll firstPart = modFix( (ll) a * (ll)value , p);
        ll secondPart = modFix(firstPart + (ll) b, p);
        
        return secondPart % m;
    }
    
    pair<int, int> insert(int value)
    {
        int index = hashFunction(value);
        list<pair<int, int> > ::iterator itr = T[index].begin();
        for(; itr!=T[index].end(); itr++){
            if(value == itr->second){
                itr->first +=1;  // **** potional BUg ****
                return {itr->first, itr->second};
            }
        }
        
        // insert new one 
        T[index].push_back({1, value});
        return {1, value};
    }
    
    vector<int> getSum_withMaxFreq()
    {
        int maxF = 0;
        for(int i=0; i<m; i++){
            list<pair<int, int> > ::iterator itr = T[i].begin();
            for(; itr!=T[i].end(); itr++)
                maxF = max(maxF, itr->first);
        }
        
        vector<int> res;
        for(int i=0; i<m; i++){
            list<pair<int, int> > ::iterator itr = T[i].begin();
            for(; itr!=T[i].end(); itr++)
                if(itr->first == maxF)
                    res.push_back(itr->second);
        }
        
        return res;
    }
};

class Solution {
    int calcSubTreeSum(TreeNode *root, hashTable &freq)
    {
        if(root == nullptr)
            return 0;
        
        int sum = 0;
        sum +=calcSubTreeSum(root->left, freq);
        sum +=calcSubTreeSum(root->right, freq);
        sum +=root->val;
        
        freq.insert(sum);
        return sum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        hashTable freq ;        
        calcSubTreeSum(root, freq);
        return freq.getSum_withMaxFreq();
    }
};
