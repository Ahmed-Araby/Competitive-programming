#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, c=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> o, e;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(i%2==0)
                e.push_back(x);
            else
                o.push_back(x);
        }

        sort(e.begin() , e.end());
        sort(o.begin(), o.end());

        int index = -1;
        for(int i=0; i<min(e.size() , o.size()); i++){
            if(e[i] > o[i]){
                index = i+i;
                break;
            }
            else if(i+1 < e.size() && o[i] > e[i+1]){
                index = i+i+1;
                break;
            }
        }
        cout<<"Case #"<<c++<<": ";
        if(index==-1)
            cout<<"OK"<< endl;
        else
            cout<<index<< endl;
    }
    return 0;
}
