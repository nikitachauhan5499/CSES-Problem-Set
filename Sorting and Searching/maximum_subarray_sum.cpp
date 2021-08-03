#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll maxsumsubarray(vector<ll> v) {
    ll sum = 0, maxi = INT_MIN;
    for(int i=0;i<v.size();i++) {
        sum = max(sum+v[i], v[i]);
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxsumsubarray(arr)<<endl;
    return 0;
}