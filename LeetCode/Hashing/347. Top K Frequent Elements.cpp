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
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // complexity O(Nlog(k));

 
        
        hashTable freq;
        
        set< pair<int , int> > topK; // freq , number
        
        for(int i=0; i<nums.size(); i++){
            pair<int , int> cur = freq.insert(nums[i]);
            int fr = cur.first;
            
            if(topK.size() < k && 
               topK.find({fr - 1, nums[i]}) == topK.end() )
               
                topK.insert({fr , nums[i]});
            
            else{
                /*
                we can't edit the element pointed to 
                by the iterator directly , as this will corrept 
                the BBS tree varient
                */
                
                set<pair<int, int> >:: iterator itr = topK.find({fr - 1, nums[i]});
                if(itr !=topK.end())
                {
                    topK.erase(itr);
                    topK.insert({fr , nums[i]});
                }
                
                else{
                    pair<int, int> tmp = *(topK.begin());
                    int tmpF = tmp.first;
                    int leastNum = tmp.second;
                    
                    if(tmpF < fr ){
                        topK.erase(topK.begin());
                        topK.insert({fr ,  nums[i]});
                    }
                }
            }
        }
        
        vector<int> res;
        set<pair<int , int> > ::iterator itr = topK.begin();
        for(; itr!=topK.end(); itr++)
            res.push_back(itr->second);
        return res;
      
    }
};
