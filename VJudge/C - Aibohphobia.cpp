// https://vjudge.net/contest/430686#problem/C

#include <iostream>
using namespace std;
int solve(string &s, int l , int h, int **dp)
{
    if(l>=h)
        return 0;

    int &ret = dp[l][h];
    if(ret !=-1) return ret;

    if(s[l]==s[h])
        return ret = solve(s, l+1, h-1, dp);

    ret = solve(s, l+1, h, dp)+1;
    ret = min(solve(s, l, h-1, dp)+1, ret);
    return ret;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int **dp = new int*[s.size()+1];
        for(int i=0; i<=s.size(); i++){
            dp[i] = new int [s.size()+1];
            for(int j=0; j<=s.size(); j++)
                dp[i][j] = -1;
        }
        int res = solve(s, 0, s.size()-1, dp);
        cout<<res<< endl;
    }
    return 0;
}
