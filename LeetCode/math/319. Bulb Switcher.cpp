class Solution {
public:
    int bulbSwitch(int n) {
        int sq= sqrt(n), cnt = 0;
        for(int i=1; i<=sq; i++){
            if(i*i <=n) // light = 1
                cnt +=1;
        }
    
        return cnt;
    }
};
