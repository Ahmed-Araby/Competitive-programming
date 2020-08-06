/*
faster , less memory solution 
https://leetcode.com/problems/data-stream-as-disjoint-intervals/discuss/744718/C%2B%2B-or-O(n)-addNums-or-O(1)-getIntervals-or-99-faster-or-98-less-memory-or-No-sets
*/
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    set<int> nums;
    
    SummaryRanges() {
    }
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        // O(N) , N -:>> is number of intervals so far 
        //total O(n^2), n-:>> size of numbers stream 
        // this handle the follow up note , as I will not do merging unless Iam asked to 
        
        vector<vector<int> > intervals;
        
        set<int> ::iterator itr = nums.begin();
        int s = *itr;
        int e = s;
        itr++;
        
        vector<int> subInterval(2);
        
        for(; itr!=nums.end(); itr++){
            int tmpe = *itr;
            if(tmpe-e > 1){
                
                subInterval[0] = s;
                subInterval[1] = e;
                intervals.push_back(subInterval);  
                // ^^^^ copy , this could be a huge problem in other languages cuz of reference 
                
                s = tmpe;
                e = tmpe;
            }
            else
                e = tmpe;
        }
        
        // last/ only interval 
        subInterval[0] = s;
        subInterval[1] = e;
        
        intervals.push_back(subInterval);
        // last part 
        
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 
 -- so each time I get new number into the stream 
    the judege will expect to have an output 
    
 */
