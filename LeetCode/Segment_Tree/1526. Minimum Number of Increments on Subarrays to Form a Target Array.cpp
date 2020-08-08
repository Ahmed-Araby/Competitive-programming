// segment tree - divide and conquer solution
struct segment_tree
{
    pair<int, int> *t;
    int n;
    segment_tree(int _n){
        n = _n * 4 +5;
        t = new pair<int , int> [n];
        return ;
    }
    
    pair<int , int> get_min(pair<int , int> a, pair<int , int> b){
        return a.first <= b.first? a:b;
    }
    
    void build(int v, vector<int> &arr, int l, int r){
        if(l==r){
            t[v] = {arr[l], l};
            return ;
        }
        
        int mid = (l+r)/2;
        build(v*2, arr, l, mid);
        build(v*2 +1, arr, mid+1, r);
        
        t[v] = t[v*2].first <= t[v*2+1].first ? t[v*2]:t[v*2+1];
        return ;
    }
    
    pair<int, int> query_min(int v, int l , int r, int tl , int tr){
        if(tl > tr){
            return {INT_MAX, -1};
        }
        
        if(l == tl && r == tr){
            return t[v];
        }
        
        int mid = (l+r) / 2;
        pair<int, int> left = query_min(v*2, l , mid, tl , min(mid , tr));
        pair<int, int> right = query_min(v*2+1, mid+1, r, max(mid+1, tl), tr);
        
        return get_min(left, right);
    }
};


class Solution {
private:
    segment_tree *seg;
public:
    int d_and_c(vector<int>& target, segment_tree * seg, int l, int r, int val){
        if(l>r)
            return 0;
        
        if(l==r)
        {
            return target[l] - val; 
        }
        
        pair<int , int> tmp = seg->query_min(1, 0, target.size()-1, l , r);
        int min_val = tmp.first;
        int split_index = tmp.second;
        
        return min_val - val + d_and_c(target, seg, l, split_index-1, min_val) +
            d_and_c(target, seg, split_index+1, r, min_val);
    }
    
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        seg = new segment_tree(n);
        seg->build(1, target, 0 , n-1);
        
        // solve the problem using divide and conquer 
        return d_and_c(target, seg, 0, n-1, 0);
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// gready solution 

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int cnt = 0;
        int max = 0;
        int n = target.size();
        
        for(int i=0; i<n; i++){
            if(target[i] >= max)
                cnt += (target[i] - max);
            max = target[i];
        }
        return cnt;
        
    }
};
