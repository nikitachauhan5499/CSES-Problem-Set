#include<iostream>
#define ll long long
using namespace std;

ll arr[200000];
ll seg[400000];
ll mini = -2147483648;

void preprocess(ll idx, ll lo, ll hi) {
    if(lo == hi) {
        seg[idx] = arr[lo];
        return;
    }
    ll mid = (lo + hi)/2;
    preprocess(2*idx+1, lo, mid);
    preprocess(2*idx+2, mid+1, hi);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

void update(ll idx, ll i, ll val, ll lo, ll hi) {
    if(lo == hi) {
        arr[lo] = val;
        seg[idx] = arr[lo];
        return;
    }
    ll mid = (lo + hi)/2;
    update(2*idx+1, i, val, lo, mid);
    update(2*idx+2, i, val, mid+1, hi);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

ll query(ll idx, ll a, ll b, ll lo, ll hi) {
    if(lo > b || hi < a) return mini;
    if(lo >= a && hi <= b) return seg[idx];
    ll mid = (lo + hi)/2;
    ll left = query(2*idx+1, a, b, lo, mid);
    ll right = query(2*idx+1, a, b, mid+1, hi);
    ll ans = max(left, right);
    if(left!=mini && right!=mini) ans = max(ans, left+right);
    return ans;
}

int main() {
    ll n, q;
    cin>>n>>q;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    preprocess(0, 0, n-1);
    for(ll i=0;i<q;i++) {
        int c, a, b;
        cin>>c>>a>>b;
        if(c == 1) {
            update(0, a-1, b, 0, n-1);
        } else {
            cout<<query(0, a-1, b-1, 0, n-1)<<endl;
        }
    }
    return 0;
}