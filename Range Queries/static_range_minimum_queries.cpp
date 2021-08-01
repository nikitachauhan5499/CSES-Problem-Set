// Segment Tree implementation

#include<iostream>
#include<vector>
using namespace std;

int arr[200001], seg[4 * 200001];

void constructTree(int idx, int lo, int hi) {
    if(lo == hi) {
        seg[idx] = arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    constructTree(2*idx+1, lo, mid);
    constructTree(2*idx+2, mid+1, hi);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

int query(int idx, int lo, int hi, int l, int r) {
    if(lo >= l && hi <= r) {
        return seg[idx];
    }
    if(hi < l || lo > r) {
        return 1e9;
    }
    int mid = (lo + hi)/2;
    int left = query(2*idx+1, lo, mid, l, r);
    int right = query(2*idx+2, mid+1, hi, l, r);
    return min(left, right);
}

int main() {
    int n, q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    constructTree(0, 0, n-1);
    for(int i=0;i<q;i++) {
        int l, r;
        cin>>l>>r;
        cout<<query(0, 0, n-1, l-1, r-1)<<endl;
    }
    return 0;
}