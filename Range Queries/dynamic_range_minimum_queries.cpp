#include<iostream>
using namespace std;

long long arr[200001];
long long seg[4 * 200001];

void constructSegment(int idx, int lo, int hi) {
    if(lo == hi) {
        seg[idx] = arr[lo];
        return;
    }
    int mid = (lo + hi)/2;
    constructSegment(2*idx+1, lo, mid);
    constructSegment(2*idx+2, mid+1, hi);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

void update(int idx, int val, int lo, int hi,int node) {
    if(lo == hi) {
        seg[idx] = val;
        return;
    }
    int mid = (lo + hi)/2;
    if(node <= mid && node >= lo) {
        update(2*idx+1, val, lo, mid, node);
    } else {
        update(2*idx+2, val, mid+1, hi, node);
    }
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

long long query(int idx, int lo, int hi, int l, int r) {
    if(hi < l || lo > r) {
        return 1e9;
    }
    if(lo >= l && hi <= r) {
        return seg[idx];
    }

    int mid = (lo + hi)/2;
    long long left = query(2*idx+1, lo, mid, l, r);
    long long right = query(2*idx+2, mid+1, hi, l, r);
    return min(left, right);
}

int main() {
    int n, q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    constructSegment(0, 0, n-1);
    while (q--) {
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 1) {
            update(0, c, 0, n-1, b-1);
        } else {
            cout<<query(0, 0, n-1, b-1, c-1)<<endl;
        }
    }
    return 0;
}