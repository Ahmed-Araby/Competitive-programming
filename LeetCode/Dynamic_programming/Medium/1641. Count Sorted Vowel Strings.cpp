#define ll long long 
class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1)
            return 5;
        ll pm[] = {1, 1, 1, 1, 1};
        ll sum = 5;
        for(int i=2; i<=n; i++){
            
            ll nm[] = {0, 0, 0, 0, 0};
            ll tmpSum = 0;
            
            for(int j=0; j<5; j++){
                nm[j] = sum -tmpSum;
                tmpSum+=pm[j];
                // update
                pm[j] = nm[j];
            }
            
           sum = 0;
            for(int j=0; j<5; j++)
                sum +=pm[j];
        }
        
        return sum;
    }
};
