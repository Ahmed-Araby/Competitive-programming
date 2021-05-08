/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    /*
        will return the same new reference to the node
        when ever it get called on the same Node.
    */
    
    Node* dfs(Node *node, map<Node*, Node*> &vis) // old, new
    {
        if(node==0)
            return 0;
        
        map<Node*, Node*> ::iterator itr = vis.find(node);
        if(itr!=vis.end())
            return itr->second;
        
        Node *newNode = new Node(node->val);
        vis[node]=newNode;
        
        int n = node->neighbors.size();
        for(int i=0; i<n; i++){
            Node* child = node->neighbors[i];
            Node *newChild = dfs(child, vis);
            newNode->neighbors.push_back(newChild);
        }
        
        return newNode;
    }
    
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> vis;
        Node* newHead = dfs(node, vis);
        return newHead;
    }
};
