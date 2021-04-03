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


//////////////////////////////////////////////// --- Tabular solution --- ////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
int get(int **dp, int n, int m, int i, int j)
{
    if(i<0 || i >=n)
        return 0;
    else if(j<0 || j>=m)
        return 0;
    return dp[i][j];
}
int solve(string &s, int **dp)
{
    // tabular form
    int n = s.size();
    for(int i=n-1;  i>=0; i--){
        for(int j=0; j<n; j++){
            if(i>=j)
                dp[i][j] = 0;
            else{
                if(s[i]==s[j]){
                    dp[i][j] = get(dp, n, n, i+1, j-1);
                    continue;
                }
                int ans = 1e8;
                ans = get(dp, n, n,i+1, j) + 1;
                ans = min(ans, get(dp, n, n, i, j-1) + 1);
                dp[i][j] = (ans == 1e8?0:ans);
            }
        }
    }
    return dp[0][n-1];
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
        }
        int res = solve(s, dp);
        cout<<res<< endl;
    }
    return 0;
}
