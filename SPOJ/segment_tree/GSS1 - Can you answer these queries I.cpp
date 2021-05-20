// wrong answer 
// cp algorithm introduced this idea
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int maxi, tot, suf, pref;
    node(int maxi, int tot, int suf, int pref)
    {
        this->maxi = maxi;
        this->tot = tot;
        this->suf = suf;
        this->pref = pref;
        return ;
    }
    node()
    {

    }
};

struct seg_tree
{
    node *t;
    int n;
    seg_tree(int _n)
    {
        n = 4 * _n  + 2;
        t = new node[n];
    }

    node create_node(int val)
    {
        int maxi = max(val, 0);
        return node(maxi, val, maxi, maxi);
    }

    node combine(node l, node r)
    {
        node newNode;

        newNode.maxi = max(l.maxi, r.maxi);
        newNode.maxi = max(newNode.maxi, l.suf + r.pref);

        newNode.tot = l.tot  + r.tot;

        newNode.pref = max(l.pref, l.tot + r.pref);
        newNode.suf = max(r.suf, r.tot + l.suf);

        return newNode;
    }

    void build(int *a, int v, int tl, int tr)
    {
        if(tl==tr){
            t[v] = create_node(a[tl]);
            return ;
        }
        int mid = (tl + tr) / 2;
        build(a, v*2, tl, mid);
        build(a, v*2+1, mid+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }

    node query(int v, int tl, int tr, int l, int r)
    {
        if(l>r)
            return create_node(-15008);

        if(tl==l && tr == r)
            return t[v];
        int mid = (tl + tr) / 2;
        node left = query(v*2, tl, mid, l, min(mid, r));
        node right = query(v*2+1, mid+1, tr, max(mid+1, l), r);
        return combine(left, right);
    }
};

int main()
{
    int n;
    cin>>n;
    int *a = new int [n+1];
    for(int i=0; i<n; i++)
        cin>>a[i];
    seg_tree seg(n);
    seg.build(a, 1, 0, n-1);

    int m;
    cin>>m;
    while(m--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        node res = seg.query(1, 0, n-1, l, r);
        cout<<res.maxi<< endl;
    }
    delete []a;
    return 0;
}
