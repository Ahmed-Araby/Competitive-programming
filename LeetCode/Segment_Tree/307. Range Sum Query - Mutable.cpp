struct segment_tree
{
    // sum in range , update
    
    int *t, n;
    segment_tree(int _n){
        n = _n * 4;
        t  = new int [n];
    }
    
    void build(int v , vector<int>& arr , int l , int r){
        if(l > r)
            return ;
        
        if(l==r){
            t[v] = arr[l];
            return;
        }
        
        int mid = (l+r)/2;
        build(v*2, arr, l, mid);
        build(v*2+1, arr, mid+1, r);
        t[v] = t[v*2] + t[v*2+1];
        return ;
    }
    
    void update(int v, int l, int r , int index , int val){
        if(l==r && l==index){
            t[v] = val;
            return ;
        }
        
        int mid = (l+r) /2;
        if(index <= mid)
            update(v*2, l, mid, index, val);
        else
            update(v*2+1, mid+1, r, index, val);
        t[v] = t[v*2] + t[v*2+1];
        return ;
    }
    
    int query(int v , int l , int r , int tl , int tr)
    {
        if(tl > tr) // invalid case 
            return 0;
        
        if(l==tl && r==tr){
            return t[v];
        }
        
        int mid = (l+r) / 2;
        int leftsum = query(v*2, l, mid, tl, min(mid , tr));
        int rightsum = query(v*2+1, mid+1, r, max(mid+1, tl), tr);
        
        return leftsum + rightsum;
    }
};
class NumArray {
private:
    segment_tree *seg;
    int n;
    
public:
    NumArray(vector<int>& nums) {
      
        
        seg = new segment_tree(nums.size());
        seg->build(1, nums, 0, nums.size()-1);
        
        n = nums.size();
        
        return ;
    }
    
    void update(int i, int val) {
        seg->update(1, 0 , n-1, i, val);
        return ;
    }
    
    int sumRange(int i, int j) {
        int sum = seg->query(1, 0, n-1, i, j);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
