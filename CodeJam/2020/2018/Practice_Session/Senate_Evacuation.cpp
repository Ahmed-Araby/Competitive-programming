#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int t, ca=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *a = new int [n] , tot=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            tot+=a[i];
        }
        vector<string> ins;
        while(tot>0)
        {
            vector<char> tmp;
            int index = -1;
            for(int i=0; i<n; i++){
                if(a[i] > (tot-1)/2)
                {
                    tmp.push_back('A'+i);
                    a[i]-=1;
                    tot-=1;
                }
                else if(a[i])
                    index = i;
            }
            string step = "";
            for(int i=0; i<tmp.size(); i++)
                step+=tmp[i];
            if(step=="") // no party is danger 
            {
                a[index]-=1;
                tot-=1;
                step += 'A' + index;
            }
            ins.push_back(step);
        }

        cout<<"Case #"<<ca++<<": ";
        for(int i=0; i<ins.size(); i++)
            cout<<ins[i]<<" ";
        cout<< endl;
    }
    return 0;
}
