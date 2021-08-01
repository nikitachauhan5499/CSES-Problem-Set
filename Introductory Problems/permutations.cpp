#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin>>n;
    vector<ll> v;
    ll i = 2, j = 1;
    while(i <= n) {
        if(i<=n)
            v.push_back(i);
        i += 2;
    }
    while(j <= n) {
        if(j <= n)
            v.push_back(j);
        j += 2;
    }
    if(n == 1) {
        cout<<1;
    } else if(n <= 3) {
        cout<<"NO SOLUTION";
    } else {
        for(int k=0;k<v.size();k++) cout<<v[k]<<" ";
    }
    return 0;
}