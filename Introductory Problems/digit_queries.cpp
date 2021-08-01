#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main() {
    int q;
    cin>>q;
    vector<ll> power10(19, 1);
    for(int i=1;i<19;i++) power10[i] = power10[i-1]*10;
    while(q--) {
        ll n;
        cin>>n;
        ll dsf = 0;
        ll prevdig = 0;
        ll nod = 0;
        for(int i=0;i<=18;i++) {
            dsf += (power10[i] - power10[i-1])*i;
            if(dsf >= n) {
                nod = i;
                break;
            }
            prevdig += (power10[i] - power10[i-1])*i;
        }
        ll lo = power10[nod-1], hi = power10[nod]-1;
        ll ans = 0;
        ll stans;
        while(lo <= hi) {
            ll mid = (lo + hi)/2;
            ll st = prevdig + 1 + (mid - power10[nod-1])*nod;
            if(st <= n) {
                if(mid > ans) {
                    ans = mid;
                    stans = st;
                }
                lo = mid+1;
            } else hi = mid-1;
        }
        string num = to_string(ans);
        cout<<num[n - stans]<<endl;
    }
    return 0;
}