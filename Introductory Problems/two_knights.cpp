#include<iostream>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++) {
        ll ans = ((i*i)*(i*i - 1)) - 48 - (40*(i-4)) - ((i-4)*(i-4)*8);
        ans = ans/2;
        cout<<ans<<endl;
    }
    return 0;
}