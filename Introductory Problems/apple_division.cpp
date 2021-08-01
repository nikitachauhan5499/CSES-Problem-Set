#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solver(vector<ll>& v, int i, ll p1, ll p2, ll &ans) {
    if(i == v.size()) {
        ans = min(ans, abs(p2-p1));
        return;
    }
    solver(v, i+1, p1+v[i], p2, ans);
    solver(v, i+1, p1, p2+v[i], ans);
}
int main() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll ans = INT_MAX;
    solver(v, 0, 0, 0, ans);
    cout<<ans<<endl;
    return 0;
}