class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int *sf = new int [26];
        int *tf = new int [26];
        for(int i=0; i<26; i++)
            sf[i]= tf[i]= 0;
        for(int i=0; i<n; i++){
            sf[s[i]-'a'] +=1;
            tf[t[i]-'a'] +=1;
        }
        
        int minOps = 0;
        for(int i=0; i<26; i++)
            minOps+= sf[i]-tf[i] >0?sf[i]-tf[i]:0;
        return minOps;
        
    }
};
