/*
lazy propogation play a very essiential role in 
dynamic segment tree
*/

struct Node
{
    Node * left , *right;
    int l , r;
    int min_val;
    
    // to aboid buidling both childs, whith no need 
    int lazy;
    
    Node()
    {
        /*
        by default any  new node should be lazy 
        as childs of this node are not constructed yet 
        */
        
        left = right = NULL;
        min_val = 0;
        lazy = 0;
        l = r = -1;
        
        return;
    }
    
    Node(int _l , int _r)
    {
        left = right = NULL;
        min_val = 0;
        lazy = 0;
        
        // range that this node can answer queries for 
        l = _l;
        r = _r;
        
        return ;
    }
    
    Node *lc(){
        if(left==NULL){
            int mid = (l+r) /2;
            
            // pushing laziness will; give this node it's ionformation
            left = new Node(l ,mid);
        }
        return left;
    }
    
    Node *rc(){
        if(right==NULL){
            int mid = (l+r)/2;
            
            right = new Node(mid+1, r);
        }
        return right;
    }
};

struct dynamic_segment_tree
{
private:    
    
    Node *root;
    const int end = 1e9;
    
private:
    int update(Node *root, int l , int r, int tl, int tr, int val){
        if(tl > tr)
            return root->min_val;
        
        if(l == tl && r==tr){
            root->min_val = val;
            /*
            we could check for being actual leef 
            and ignore the lazy value if it is
            */
            
            root->lazy = val; // 0 or 1 
            return val;
        }
        
        int mid = (l+r) / 2;
        
        int left  = 1;
        int right = 1;
        
        // build childs if needed 
        root->left = root->lc();
        root->right = root->rc();
        
        // push lazyiness 
        push_lazyiness(root); // left
        
        // continue updating 
        left = update(root->left, l, mid, tl , min(mid ,tr), val);
        // continue updating 
        right = update(root->right, mid+1, r, max(mid+1, tl), tr, val);
        
        // relfect updating
        root->min_val = min(left, right);
        return root->min_val;
    }
    
    int query(Node *root, int l ,int r , int tl, int tr){
        if(tl>tr)
            return 1;
        
        if(l==tl && r==tr){
            return root->min_val;
        }
        
        int mid = (l+r) / 2;
        int left = 1, right = 1;
    
        // build childs if needed 
        root->left = root->lc();
        root->right = root->rc();
        
        // push lazyiness 
        push_lazyiness(root);

        // query 
        left = query(root->left, l, mid, tl, min(mid, tr));
        right = query(root->right, mid+1, r, max(mid+1, tl),  tr);
        
        return min(left , right);
    }
    
    void push_lazyiness(Node *root)
    {
        if(root->lazy!=-1){
            root->lazy = -1;
            int min_val = root->min_val;
            root->left->min_val = min_val;
            root->left->lazy = min_val;
            
            root->right->min_val = min_val;
            root->right->lazy = min_val;
        }
        return ;
    }
    
public:
    
    dynamic_segment_tree(int l , int r){
        root =  new Node(l , r);
        return ;
    }
    
    void update(int l, int r , int val){
        update(root, 0, end, l, r, val);
        return ;
    }
    
    int query_min(int l , int r){
        return query(root, 0, end, l , r);
    }
};



class RangeModule {
    dynamic_segment_tree *seg;
public:
    RangeModule() {
        // no one is tracked yet
        seg = new dynamic_segment_tree(0, 1e9);
    }
    
    void addRange(int left, int right) {
        seg->update(left, right-1, 1);
    }
    
    bool queryRange(int left, int right) {
        int minValInRange = seg->query_min(left, right-1);
        return minValInRange==1;
    }
    
    void removeRange(int left, int right) {
        seg->update(left, right-1, 0);
    }
};



/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
