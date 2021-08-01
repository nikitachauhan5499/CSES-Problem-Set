#include<iostream>
#define ll long long
using namespace std;

ll arr[200001];
ll seg[4 * 200001];
void preprocess(int idx, ll lo, ll hi) {
    if(lo == hi) {
        seg[idx] = arr[lo];
        return;
    }
    ll mid = (lo + hi)/2;
    preprocess(2*idx+1, lo, mid);
    preprocess(2*idx+2, mid+1, hi);
}

void update_segment(ll i, ll val, ll idx, ll lo, ll hi) {
    if(lo == hi) {
        arr[lo] = val;
        seg[idx] = val;
        return;
    }
    ll mid = (lo + hi)/2;
    if(mid >= i) {
        update_segment(i, val, 2*idx+1, 0, mid);
    } else {
        update_segment(i, val, 2*idx+2, mid+1, hi);
    }
}

ll query(ll a, ll b, ll lo, ll hi) {
    if(lo == hi) {
        return arr[lo] >= a && arr[lo] <= b;
    }
    ll mid = (lo + hi)/2;
    ll left = query(a, b, lo, mid);
    ll right = query(a, b, mid+1, hi);
    return left + right;
}
int main() {
    ll n, q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    preprocess(0, 0, n-1);
    for(int i=0;i<q;i++) {
        char ch;
        cin>>ch;
        ll k, x;
        cin>>k>>x;
        if(ch == '?') {
            cout<<query(k, x, 0, n-1)<<endl;
        } else {
            update_segment(k-1, x, 0, 0, n-1);
        }
    }
    return 0;
}