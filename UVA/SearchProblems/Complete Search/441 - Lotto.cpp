#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int sz = 50;

void dispGame(int *g, int n){
    for(int i=0; i<n; i++) {
        cout << g[i];
        cout<<(i+1==n?"":" ");
    }
    cout<< endl;
    return ;
}

void playGames(int pos, int lci,
                int *arr, int sz ,int lim,
                int* game)
{
    if(pos == lim) {
        dispGame(game, lim);
        return ;
    }
    for(int i=lci+1; i<sz; i++){
        if(sz - i < lim-pos)
            break;
        game[pos] = arr[i];
        playGames(pos+1, i,
                  arr, sz, lim, game);
    }
    return ;
}
int main()
{
    int a[sz], g[sz];
    bool f = true;
    while(true)
    {
        int k;
        cin>>k;
        if(k == 0)
            break;

        if(!f)
            cout<<endl;
        f = false;


        for(int i=0; i<k; i++)
            cin>>a[i];
        sort(a, a+k);
        playGames(0, -1,
                  a, k, 6, g);
    }
    return 0;
}
