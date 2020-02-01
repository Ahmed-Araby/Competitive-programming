// https://codeforces.com/contest/1282/problem/D
#include <bits/stdc++.h>
#define pi pair<string, int>
using namespace std;
const int sz = 300;

pi get_right_length()
{
    string sa="", sb="";
    for(int i=0; i<sz; i++){
        sa += 'a';
        sb += 'b';
    }
    // interactive part
    // am I need to do flush after the cin>> !????

    int dis1=0 , dis2=0;
    cout<<sa<< endl;
    cout.flush();
    cin>>dis1;
    cout<<sb<< endl;
    cout.flush();
    cin>>dis2;

    // case of right distance
    if(dis1+dis2==sz)
        return {sa , dis1};
    // other wise
    int extra = dis1+dis2-sz; // could be proved with simple math
    sa.resize(sz-extra);  // return none
    return {sa, dis1-extra};
}

int main()
{
    //cout<<"here"<< endl;
    pi tmp = get_right_length(); // 2 quires
    string cs = tmp.first;
    int edis = tmp.second;
    //cout<<edis<< endl;
    for(int i=0; i<cs.size(); i++){
        int tdis = 0;
        if (edis!=0)
            cs[i]='b'; // flip

        cout<<cs<< endl;
        cout.flush();
        cin>>tdis;
        if(tdis==-1)
            exit(0);

        if(tdis>edis) // flip back
            cs[i]='a';
        if(tdis<edis)
            edis = tdis;
        if(tdis==0)
            exit(0);
    }
}
