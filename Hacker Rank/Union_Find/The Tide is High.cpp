
/*
not solved yet
*/
#include <bits/stdc++.h>
#define pi pair<int ,int>
#define ll long long
using namespace std;

struct dsu
{
    int *p, *s;
    int rows , cols;
    map<pi, int> left;
    ll totProd;

    dsu(int _rows, int _cols)
    {
        totProd = 0;
        int n = _rows * _cols;
        rows  = _rows;
        cols  = _cols;

        p = new int [n+2];
        //r = new int [n+2];
        s = new int [n+2];
        for(int i=0; i<=n; i++){
            p[i] = i;
            //r[i] = 0;
            s[i] = 1;
        }
        return ;
    }

    void calcTot(string * m)
    {
        set<int> roots;
        for(int i=0; i<rows*cols; i++){
            // i is a root;

            pi cor = unflatten(i);
            int root = _find(i);

            if(m[cor.first][cor.second] !='#')
                continue;

            //cout<<cor.first<<" "<<cor.second<< endl;
            if(roots.find(root) == roots.end()){
                int totSize = getTotSize(root);
                totProd += totSize * totSize;
                //cout<<totSize<<" "<<root<< endl;
                roots.insert(root);
            }
        }
        return;
    }


    ll getTotProd()
    {
        return totProd;
    }

    int getTotSize(int root)
    {
        /*
        return size of the component
        rooted at root
        */
        root = _find(root);
        return s[root];

    }

    int getLeftSize(int root, int col)
    {
        /*
        return number of elements in my
        forest to my left
        */
        root = _find(root);
        return left[{root, col}];

    }

    int flatten(int i, int j)
    {
        return i * cols + j;
    }

    pair<int , int> unflatten(int index)
    {
        return {index / cols, index%cols};
    }

    int _find(int row, int col)
    {
        int index = flatten(row, col);
        return _find(index);
    }

    int _find(int index)
    {
        return p[index] == index ? index: p[index] = _find(p[index]);
    }

    void _union(int i1, int j1, int i2, int j2)
    {
        // row, col , row , col
        /*
        i1 and j1 is to left or above
        the cell at i2 , j2
        */

        int a = flatten(i1, j1);
        int b = flatten(i2, j2);

        int pa = _find(a);
        int pb = _find(b);
        if(pa == pb)
            return ;
        else{
            p[pb] = pa;
            //cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<< endl;

            if(j2 == j1+1 && left.find({pa, j2}) == left.end()){
                left[{pa, j2}] = s[pa] + left[{pb, j2}];
            }


            s[pa] +=s[pb];
        }
        return ;
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>>row>>col;
        string * m = new string[row];
        for(int i=0; i<row; i++)
            cin>>m[i];

        dsu dsuObj(row, col);

        for(int i=0; i<col; i++)
        {
            for(int j=0; j<row; j++){
                if(m[j][i]=='#'){
                    //cout<<"here"<< endl;
                    // check lower
                    if(j+1 < row && m[j+1][i]=='#')
                        dsuObj._union(j, i, j+1, i);
                    // check left
                    if(i-1 >=0 && m[j][i-1]=='#')
                        dsuObj._union(j, i-1, j, i);
                }
            }
        }

        dsuObj.calcTot(m);

        //cout<<dsuObj.getTotProd()<< endl;
        for(int i=0; i<col; i++){
            // disable this col
            map<int , int> g;
            for(int j=0; j<row; j++){
                if(m[j][i]!='#')
                    continue;

                int root = dsuObj._find(j, i);
                g[root]++;
            }
            map<int , int> ::iterator itr = g.begin();
            int res = dsuObj.getTotProd();
            for(; itr!=g.end(); itr++){

                // now we are holding a root
                int totSize = dsuObj.getTotSize(itr->first);
                int left = dsuObj.getLeftSize(itr->first, i);
                // left not including me
                res -= totSize*totSize;
                int right = totSize - left - itr->second;
                if(i == 12)
                cout<<"here"<<" "<<left<<" "<<right<<" "<<totSize<<" "<<i<< endl;
                res += left * left + right * right;
            }
            cout<<res<<endl;
        }
        cout<< endl;

    }
    return 0;
}
