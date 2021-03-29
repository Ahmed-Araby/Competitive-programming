#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> sieve(int n)
{
    bool *isPrime = new bool[n+1];
    for(int i=0; i<=n; i++)
        isPrime[i] = true;
    vector<int> ps;

    isPrime[0] = isPrime[1] = false;
    ps.push_back(2);
    for(int i=3; i<=n; i+=2){ // odds - i
        if(isPrime[i]){
            ps.push_back(i);
            for(long long j=(ll)i*i; j<=n; j+=2*i)
                isPrime[j] = false;
        }
    }

    delete  [] isPrime;
    return ps;
}

