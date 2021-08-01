#include<iostream>
#define ll long long
using namespace std;

ll mod = 1e9+7;

ll calcpower(ll x, ll y) {
    ll ans = 1;
    x %= mod;
    while(y) {
        if(y&1) ans = (ans*x)%mod;
        y>>=1;
        x = (x*x)%mod;
    }
    return ans;
}

int main() {
    ll n;
    cin>>n;
    cout<<calcpower(2, n);
}