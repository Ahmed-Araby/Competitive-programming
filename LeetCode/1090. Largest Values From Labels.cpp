class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        
        int n = values.size();
        
        pair<int, int> *arr  = new pair<int, int> [n];
        for(int i=0; i<n; i++){
            arr[i] = {values[i], labels[i]};
        }
        
        
        int *freq = new int[20005];
        for(int i=0; i<20005; i++)
            freq[i] = 0;
        
        sort(arr, arr+n, greater<pair<int , int> > ());
        int index = 0;
        long long ans = 0;
        while(index < n && num_wanted > 0)
        {
            int label = arr[index].second;
            if(freq[label] < use_limit)
            {
                freq[label] +=1;
                ans +=arr[index].first;
                num_wanted -=1;
            }
            
            index +=1;
        }
        
        return ans;
        
    }
};
