#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll customers(vector<pair<ll, ll>>& v) {
    sort(v.begin(), v.end());
    ll ans = 0, maxi = 0;
    for(int i=0;i<v.size();i++) {
        ans += v[i].second;
        maxi = max(maxi, ans);
    }
    return maxi;
}

int main() {
    ll n;
    cin>>n;
    vector<pair<ll, ll>> v;
    for(int i=0;i<n;i++) {
        ll a, b;
        cin>>a>>b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    cout<<customers(v)<<endl;
    return 0;
}