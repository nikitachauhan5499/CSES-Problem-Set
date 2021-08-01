// Lazy Propagation

#include<iostream>
using namespace std;

long long arr[200001];
long long seg[800004], lazy[800004];

void preprocess(int idx, int lo, int hi) {
    if(lo == hi) {
        seg[idx] = arr[lo];
        lazy[idx] = 0;
        return;
    }
    int mid = (lo + hi)/2;
    preprocess(2*idx+1, lo, mid);
    preprocess(2*idx+2, mid+1, hi);
    lazy[idx] = 0;
}

void update(int idx, int l, int r, long long val, int lo, int hi) {
    if(lo > hi || hi < l || lo > r) return;
    
    if(lo >= l && hi <= r) {
        lazy[idx] += val;
        return;
    }

    int mid = (lo + hi)/2;
    update(2*idx+1, l, r, val, lo, mid);
    update(2*idx+2, l, r, val, mid+1, hi);
}

long long query(int i, int idx, int lo, int hi) {
    if(lo == hi) {
        return lazy[idx]+seg[idx];
    }
    int mid = (lo + hi)/2;
    if(i <= mid) {
        return lazy[idx]+query(i, 2*idx+1, lo, mid);
    } else {
        return lazy[idx]+query(i, 2*idx+2, mid+1, hi);
    }
}

int main() {
    int n, q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    preprocess(0, 0, n-1);
    for(int i=0;i<q;i++) {
        int a;
        cin>>a;
        if(a == 1) {
            int b, c;
            long long d;
            cin>>b>>c>>d;
            update(0, b-1, c-1, d, 0, n-1);
        } else {
            int b;
            cin>>b;
            cout<<query(b-1, 0, 0, n-1)<<endl;
        }
    }
}