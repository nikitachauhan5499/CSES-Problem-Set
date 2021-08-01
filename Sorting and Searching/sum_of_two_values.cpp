#include<bits/stdc++.h>
#define ll long long
using namespace std;

void targetsum(vector<pair<ll, ll>>& v, ll k) {
    sort(v.begin(), v.end());
    int i = 0, j = v.size()-1;
    while(i < j) {
        if(v[i].first + v[j].first == k) {
            cout<<v[i].second+1<<" "<<v[j].second+1;
            return;
        }
        if(v[i].first + v[j].first < k) {
            i++;
        } else {
            j--;
        }
    }
    cout<<"IMPOSSIBLE";
}

int main() {
    ll n, k;
    cin>>n>>k;
    vector<pair<ll, ll>> v(n);
    for(int i=0;i<n;i++) {
        ll a;
        cin>>a;
        v[i] = {a, i};
    }
    targetsum(v, k);
    return 0;
}