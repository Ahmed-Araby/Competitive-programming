#include <bits/stdc++.h>
using namespace std;
int calc_lcs(string a, string b, int **dp)
{
    int n = a.size();
    int m = b.size();
    /*
        build table bottom - up
        right - left
    */
    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            if(i==n || j==m)
                dp[i][j] = 0;
            else {
                if(a[i]==b[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

void build_lcs(string a, string b, int **dp)
{
    int i = 0, j =0;
    int n = a.size(), m = b.size();
    while(i<n && j<m)
    {
        //cout<<i<<" "<<j<< endl;
        //cout<<a[i]<<" "<<a[j]<< endl;

        int lcs = dp[i][j];
        if(a[i] == b[j]){
            cout<<a[i];
            i+=1;
            j+=1;
        }
        else{
            if(dp[i+1][j]==lcs)
                i+=1;
            else
                j+=1;
        }

    }
    return ;
}

int main()
{
    string a , b;
    cin>>a>>b;
    int as = a.size();
    int bs = b.size();

    int **dp = new int *[as+1];
    for(int i=0; i<=as; i++){
        dp[i] = new int[bs+1];
        for(int j=0; j<=bs; j++)
            dp[i][j]  = -1;
    }

    int lcs = calc_lcs(a, b, dp);
    // cout<<"LCS IS : "<<lcs<< endl;
    build_lcs(a, b, dp);

    return 0;
}
