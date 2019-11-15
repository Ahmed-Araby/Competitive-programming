class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> o;
        int n=s.size();
        for(int i=0; i<n; i++)
            if(s[i]=='(')
                o.push_back(i);
            
            else if(s[i]==')'){
                if(!o.empty())
                    o.pop_back();
                else
                    s[i]='.';
            }
        string ans="";
        for(int i=0; i<o.size(); i++)
            s[o[i]]='.';
        for(int i=0; i<n; i++)
            if(s[i]!='.')
                ans+=s[i];
        return ans;
    }
};
