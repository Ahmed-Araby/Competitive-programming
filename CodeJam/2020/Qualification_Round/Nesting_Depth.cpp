#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int t ,ca=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<char> ans;
        int prv= 0;
        for(int i=0; i<s.size(); )
        {
            int num = s[i]-'0';
            if(prv<num)
            {
                prv++;
                ans.push_back('(');
            }
            else if(prv==num){
                ans.push_back(s[i]);
                i++;
            }
            else if(prv>num){
                ans.push_back(')');
                prv--;
            }
            
            // special case 
            if(i==s.size())
            {
                while(prv){
                    ans.push_back(')');
                    prv--;
                }
            }
        }
        cout<<"Case #"<<ca++<<": ";
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i];
        cout<< endl;
    }
    return 0;
}
