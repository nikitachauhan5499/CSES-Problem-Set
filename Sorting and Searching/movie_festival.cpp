#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.second < p2.second;
}

ll movies(vector<pair<ll, ll>>& v) {
    sort(v.begin(), v.end(), comp);
    int i = 0, last = 0, ans = 0;
    while(i < v.size()) {
        if(last <= v[i].first) {
            last = v[i].second;
            ans++;
        }
        i++;
    }
    return ans;
}

int main() {
    ll n;
    cin>>n;
    vector<pair<ll, ll>> v;
    for(int i=0;i<n;i++) {
        ll a, b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    cout<<movies(v)<<endl;
    return 0;
}