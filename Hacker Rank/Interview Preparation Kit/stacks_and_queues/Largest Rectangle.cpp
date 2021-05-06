/*https://www.hackerrank.com/challenges/largest-rectangle/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=stacks-queues*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */


void clear_stack(stack<int> &s)
{
    while(!s.empty())
        s.pop();
    return ;
}

long largestRectangle(vector<int> h) {
    int n = h.size();
    int lIndex[n+1];
    int rIndex[n+1];
    stack<int> s;
    s.push(-1);
    
    // left to right
    for(int i=0; i<n; i++){
        int x = h[i];
        int index = s.top();    
        while(index !=-1 && h[index]>=x){
            s.pop();
            index = s.top();
        }
        lIndex[i] = s.top();
        s.push(i);
    }
    
    // right to left
    clear_stack(s);
    s.push(n);
    for(int i=n-1; i>=0; i--){
        int x = h[i];
        int index = s.top();
        while(index!=n && h[index]>=x){
            s.pop();
            index = s.top();
        }
        rIndex[i]=s.top();
        s.push(i);
    }
    
    // get ans
    long long ans = 0; 
    for(int i=0; i<n; i++)
        ans = max(ans, (ll)(rIndex[i] - lIndex[i] - 1 ) * (ll)h[i]);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
