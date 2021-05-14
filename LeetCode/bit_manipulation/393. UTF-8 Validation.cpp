class Solution {
public:
    bool contuationByte(int byte)
    {
        int res = pow(2, 7);
        int mask = pow(2, 7) + pow(2, 6);
        
        if((byte & mask) == res)
            return true;
        
        return false;
    }
    
    int cntPrefix(int byte)
    {
        int cnt = 0;
        for(int i=7; i>=0; i--){
            if(byte & (1<<i))
                cnt +=1;
            else 
                break;
        }
        if(cnt == 0)
            return 0;
        else if(cnt == 2)
            return 1;
        else if(cnt == 3)
            return 2;
        else if(cnt == 4)
            return 3;
        return -1;
    }
    
    bool validUtf8(vector<int>& data) {
        int n= data.size();
        int byteCnt = 0;
        bool ans = true;
        
        for(int i=0; i<n; i++){
            if(byteCnt==0){
                byteCnt = cntPrefix(data[i]);
                if(byteCnt == -1){
                    ans = false;
                    break;
                }
            }
            else 
            {
                if(contuationByte(data[i]))
                    byteCnt-=1;
                else {
                    ans = false;
                    break;
                }
            }
        }
        return ans && (byteCnt == 0);
    }
};
