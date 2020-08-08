/*
this problem is a good practice for dynamic segment trees
*/

// N^2 solution 
class MyCalendarThree {
private:
    map<int , int> mark;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mark[start] +=1;
        mark[end] -=1;
                
        int k = 1, sum = 0;
        map<int , int> ::iterator itr = mark.begin();
        for(; itr!=mark.end(); itr++){
            sum += itr->second;
            k = max(k, sum);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 /*
 solution with dynamic segment tree
 */
 
 
 
 
