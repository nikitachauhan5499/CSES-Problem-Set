#include<iostream>
#define ll long long
using namespace std;

ll solve(ll x, ll y, bool f) {
    if (f == 0) {
        return y*y - x + 1;
    } else {
        return (y-1)*(y-1) + x;
    }
}
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll x, y;
        cin>>x>>y;
        ll ans;
        if(x < y) {
            if(y%2 != 0) {
                ans = (y*y) - x + 1;
            } else {
                ans = ((y-1) * (y-1)) + x;
            }
        } else {
            if(x%2 != 0) {
                ans = (x-1) * (x-1) + y;
            } else {
                ans = x * x - y + 1; 
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}