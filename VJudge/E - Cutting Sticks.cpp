#include <bits/stdc++.h>
using namespace std;


int getS(int *cuts, int n, int s){
    int index = lower_bound(cuts, cuts+n, s+1) - cuts;
    return index;
}

int getE(int *cuts, int n, int e){
    int index = upper_bound(cuts, cuts+n, e-1) - cuts;
    index -=1;
    return index;
}

bool valid(int n, int s, int e)
{
    return (s<=e &&
            s>=0 && s<n &&
            e >=0 && e<n);
}

int solve(int s, int e,
            int *cuts, int n,
            int **dp)
{
    int &ret = dp[s][e];
    if(ret!=-1) return ret;

    int as = getS(cuts, n, s);
    int ae = getE(cuts, n, e);
    if(!valid(n, as, ae)) return ret = 0;

    ret = 1e9;
    int len = e-s;
    for(; as<=ae; as++)
        ret = min(ret, solve(s, cuts[as], cuts, n, dp) +
                        solve(cuts[as], e, cuts, n, dp) + len);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int *cuts = new int[55];
    int **dp = new int* [1000+1];
    for(int i=0; i<=1000; i++)
        dp[i] = new int [1000];

    while(true){
        int l;
        cin>>l;
        if(!l) break;
        int n; cin>>n;
        for(int i=0; i<n; i++)
            cin>>cuts[i];

        for(int i=0; i<=l; i++){
            for(int j=0; j<=l; j++)
                dp[i][j] = -1;
        }

        int res = solve(0, l, cuts, n, dp);
        cout<<"The minimum cutting is "<<res<<"."<< endl;
    }

    delete[] cuts;
    delete []dp;
    return 0;
}
