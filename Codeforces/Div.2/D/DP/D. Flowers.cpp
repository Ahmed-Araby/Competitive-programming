// https://codeforces.com/problemset/problem/474/D

#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5+5;
const int mod = 1e9+7;
int add_mod(long long a, long long b)
{
    a = a%mod;
    b = b%mod;
    return (a+b) % mod;
}

void count_ways(int *dp, int k)
{
    dp[0] = 1;
    for(int i=1; i<sz; i++){
        dp[i] = 0;
        if(i-k >=0)
            dp[i] = dp[i-k]; // k white
        dp[i] = add_mod(dp[i], dp[i-1]); // 1 red
    }
    return ;
}

int fix(long long num, int mod)
{
    return (num % mod + mod) % mod;
}
int main()
{
    int t, k;
    cin>>t>>k;
    int *dp = new int [sz];
    count_ways(dp, k);
    // cs
    for(int i=2; i<sz; i++)
        dp[i] = add_mod(dp[i-1], dp[i]);
    dp[0] = 0; // for the cs thing
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<fix(dp[b] - dp[a-1], mod)<< endl;
    }
    return 0;
}
