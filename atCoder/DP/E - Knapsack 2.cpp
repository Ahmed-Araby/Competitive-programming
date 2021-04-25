// https://atcoder.jp/contests/dp/tasks/dp_e?lang=en
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxProf = 1e5;

int get_min_w(int index, int prof,
              int *w, int *v, int n,
              int **dp)
{
    if(index == n || prof == 0){
        if(prof == 0)
            return 0;
        return 1e9+5;
    }

    if(dp[index][prof]!=-1)
        return dp[index][prof];
    long long w1 = get_min_w(index+1, prof- v[index],
                             w, v, n, dp) + w[index];
    long long w2 = get_min_w(index+1, prof,
                             w, v, n, dp);
    // avoid overflow
    w1 = min(w1, (ll)1e9+5);
    w2 = min(w2, (ll)1e9+5);

    dp[index][prof] = min(w1, w2) ;
    return dp[index][prof];
}

int main()
{
    int n, c;
    cin>>n>>c;

    int **dp = new int *[n+2];
    for(int i=0; i<=n; i++)
    {
        dp[i] = new int[maxProf+2];
        for(int j=0; j<=maxProf; j++)
            dp[i][j] = -1;
    }

    int *w = new int[n+1];
    int *v = new int [n+1];
    for(int i=0; i<n; i++)
        cin>>w[i]>>v[i];

    // try to get max profit
    int ans = 0;
    for(int i=maxProf; i>=0; i--){
        int minWeight = get_min_w(0, i,
                                    w, v, n,
                                    dp);
        if(minWeight <=c){
            ans = i;
            break;
        }
    }

    cout<<ans<< endl;

    delete []w;
    delete []v;
    delete []dp;
    return 0;
}
