#include<bits/stdc++.h>
using namespace std;

int apartments(int n, int m, vector<int> a, vector<int> b, int k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<bool> vis(m, 0);
    int count = 0;
    int i=0, j=0;
    while(i < n && j < m) {
        if(b[j] < a[i] - k) j++;
        else if(b[j] > a[i] + k) i++;
        else {
            count++;
            i++;
            j++;
        }
    }
    return count;
}

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    cout<<apartments(n, m, a, b, k);
    return 0;
}