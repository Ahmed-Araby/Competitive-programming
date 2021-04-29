// wrong answer !!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
/*
if they are equal we are not taking into
account any further characters
comparison should be done on the whole string for each sub problem 
not only the first character 
very nice solution:
https://github.com/MarioBassem/UVA-Solutions/blob/master/UVA%2011404%20-%20Palindromic%20Subsequence.cpp
*/

#include <bits/stdc++.h>
#define psi pair<char , int>

using namespace std;
const int sz = 1005;

psi get_lps(int l, int r,
            string &s,
             psi **dp)
{
    if(l>r)
        return dp[l][r] = {'z', 0}; // z for being always bigger
    if(l==r)
        return dp[l][r] = {s[l], 1};  // this was the bug


    psi &ret = dp[l][r];
    if(ret.second!=-1)
        return ret;


    if(s[l]==s[r]){
        psi tmp = get_lps(l+1, r-1, s, dp);
        ret = {s[l], tmp.second + 2};
    }
    else
    {
        psi tmp1 = get_lps(l+1, r, s, dp);
        psi tmp2 = get_lps(l, r-1, s, dp);
        if(tmp1.second == tmp2.second)
        {
            //cout<<"fc :"<<tmp1.first<<" "<<tmp2.first<< endl;
            if(tmp1.first < tmp2.first)
                ret = tmp1;
            else
                ret = tmp2;
        }
        else if(tmp1.second > tmp2.second)
            ret = tmp1;
        else
            ret = tmp2;
    }

    //cout<<ret.first<<" "<<ret.second<< endl;
    return ret;
}

string get_sub_lps(int l, int r,
                    string &s,
                     psi **dp)
{
    int lps_len = dp[l][r].second;

    string lpsP="";
    int inc = 0;
    while(true)
    {
        if(l>r)
            break;
        if(l==r){
            // odd length palindrome
            lpsP.push_back(s[l]);
            inc = 1;
            break;
        }
        if(s[l]==s[r]){
            lpsP.push_back(s[l]);
            l+=1;
            r-=1;
        }
        else{
            /*
                indexing will always be safe
                thanks to the termination cases.
            */
            psi tmp1 = dp[l+1][r];
            psi tmp2 = dp[l][r-1];
            //cout<<l<<" "<<r<< endl;
            //cout<<tmp1.first<<" "<<tmp1.second<< endl;
            //cout<<tmp2.first<<" "<<tmp2.second<< endl;
            if(tmp1.second == tmp2.second){
                //cout<<"fc :"<<tmp1.first<<" "<<tmp2.first<< endl;

                if(tmp1.first < tmp2.first)
                    l+=1;
                else
                    r-=1;
            }
            else if(tmp1.second > tmp2.second)
                l+=1;
            else
                r-=1;
        }
    }
    string ans = lpsP;
    for(int i= lpsP.size()-1-inc; i>=0; i--)
        ans.push_back(lpsP[i]);
    return ans;
}


int main()
{
    string s;
    psi ** dp = new psi*[sz];
    for(int i=0; i<sz; i++)
        dp[i] = new psi[sz];

    while(cin>>s)
    {
        int n = s.size();
        for(int i=0; i<sz; i++)
            for(int j=0; j<sz; j++)
                dp[i][j] = {'z', -1};

        get_lps(0, n-1, s, dp);
        //cout<<"here1"<< endl;
        string lps = get_sub_lps(0, n-1, s, dp);
        //cout<<"here2"<< endl;
        cout<<lps<< endl;
    }
    return 0;

}
