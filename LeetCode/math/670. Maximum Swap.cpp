class Solution {
public:
     vector<int> getD(int num)
     {
         vector<int> d;
         while(num){
             int dig = num %10;
             d.push_back(dig);
             num /=10;
         }
         
         reverse(d.begin(), d.end());
         return d;
         
     }
    vector<int> enlarge(vector<int> d)
    {
        for(int i=0; i<d.size(); i++){
            int index = -1;
            
            for(int j=i+1; j<d.size(); j++){
                if(index == -1 || d[j] >= d[index])
                    index = j;
            }
            
            if(index !=-1 && d[index] > d[i]){
                swap(d[index], d[i]);
                break;
            }
        }
        return d;
    }
    
    int vec_to_num(vector<int> d)
    {
        int num = 0;
        for(int i=0; i<d.size(); i++)
            num = num * 10 + d[i];
        return num;
    }
    
    int maximumSwap(int num) {
        vector<int> d = getD(num);
        d = enlarge(d);
        return vec_to_num(d);
    }
};
