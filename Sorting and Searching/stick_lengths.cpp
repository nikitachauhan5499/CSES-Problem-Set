#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    ll mid = arr.size()/2;
    ll ans  = 0;
    for(int i=0;i<arr.size();i++) ans+=abs(arr[i]-arr[mid]);
    cout<<ans<<endl;
    return 0;
}
