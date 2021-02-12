// https://codeforces.com/contest/27/problem/C
// output need index , but I give him the real numbers

#include <iostream>
#include <vector>
using namespace std;
struct info{
    int sml, lar;
};

void build_info(int *a, info *inf,
                int i,  int e, int dir)
{
    int maxi = -1,  mini = 1e8;
    while(i!=e){
        if(maxi > a[i])
            inf[i].lar = maxi;
        else
            inf[i].lar = -1;

        if(mini < a[i])
            inf[i].sml = mini;
        else
            inf[i].sml = 1e8;

        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
        i+=dir;
    }
    return ;
}

bool hell(int *a, info *l, info *r, int index)
{
    if(a[index] > l[index].sml &&
        a[index] > r[index].sml)
        return 1;
    return 0;
}

bool beach(int *a, info *l, info *r, int index)
{
    if(a[index] < l[index].lar &&
        a[index]  < r[index].lar)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int *a = new int [n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    info *l = new info[n];
    info *r = new info[n];
    build_info(a, l, 0, n, 1);
    build_info(a, r, n-1, -1, -1);

    // get the ans
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(hell(a, l, r, i)){
            ans.push_back(l[i].sml);
            ans.push_back(a[i]);
            ans.push_back(r[i].sml);
            break;
        }

        else if(beach(a, l ,r, i)){
            ans.push_back(l[i].lar);
            ans.push_back(a[i]);
            ans.push_back(r[i].lar);
            break;;
        }
    }

    cout<<ans.size()<<endl;
    if(!ans.empty())
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<< endl;

    delete [] a;
    delete [] l;
    delete [] r;
    return 0;
}
