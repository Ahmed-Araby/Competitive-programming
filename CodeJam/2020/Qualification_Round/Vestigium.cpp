#include <iostream>
using namespace std;
const int sz = 105;
int main()
{
    int t, ca=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int trace = 0, r=0 , c=0;
        int a[sz][sz];
        // get input , calc for row 
        for(int i=0; i<n; i++){
            bool vis[sz]={0};
            bool rep =0;
            for(int j=0; j<n; j++)
            {
                int x;
                cin>>x;
                a[i][j]=x;
                if(vis[x])
                    rep = true;
                vis[x]=1;
                if(i==j)
                    trace+=x;
            }
            if(rep)
                r+=1;
        }
        // cols
        for(int j=0; j<n; j++){
            bool vis[sz]={0};
            bool rep =0;
            for(int i=0; i<n; i++)
            {
                int x=a[i][j];
                if(vis[x]){
                    rep =1;
                    break;
                }
                vis[x]=1;
            }
            if(rep)
                c+=1;
        }
        cout<<"Case #"<<ca++<<": ";
        cout<<trace<<" "<<r<<" "<<c<< endl;
    }
    return 0;
}
