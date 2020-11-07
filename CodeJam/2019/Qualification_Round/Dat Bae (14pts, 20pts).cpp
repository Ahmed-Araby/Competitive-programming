#include <bits/stdc++.h>
using namespace std;

vector<int> detectDownWorkers(vector<string> &resps)
{
    // walk in cols to column index within a chunk
    int l = 0;
    int n = resps[0].size();
    
    vector<int> down;
    int index = 0;
    
    for(int i=0; i<n; i++){ // col
        // get column value
        int col = 0;
        for(int j=0; j<5; j++){ // row
            bool setBit = (resps[j][i] =='0'?0:1);
            col += setBit * pow(2, j);
        }
        //cout<<"col : "<<col<< endl;

        if(col > l){
            for(; l<col; l++)
                down.push_back(index++);
        }
        else if(col < l){
            for(; l<=31; l++)
                down.push_back(index++);
            for(l=0; l<col; l++)
                down.push_back(index++);
        }
        l++;
        index++;
    }
    return down;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, b;
        cin>>n>>b;

        vector<string> resps;
        // columns are the reversed
        //binary representation.
        // only 5 attempts
        for(int i=0; i<5; i++){
            string query = "";
            int level = 1 << i;
            for(int j=0; j<n; j++){
                // get the bit
                // for row and col

                int bit = (j%32) & level;
                if(bit==0)
                    query +='0';
                else
                    query +='1';
            }
            // send it to the server
            cout<<query<< endl;
            cout.flush();

            // read response
            string resp;
            cin>>resp;
            resps.push_back(resp);
        }

        // detect down workers
        vector<int> down = detectDownWorkers(resps);
        for(int i=0; i<b; i++)
            cout<<down[i]<<" ";
        cout<< endl;
        cout.flush();

        int resp;
        cin>>resp;
    }

    return 0;
}
