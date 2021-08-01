#include<bits/stdc++.h>
using namespace std;

void solver(vector<int> a, vector<int> b) {
    multiset<int, greater<int>> set;
    for(int i=0;i<a.size();i++) set.insert(a[i]);
    for(int i=0;i<b.size();i++) {
        auto it = set.lower_bound(b[i]);
        if(it == set.end()) {
            cout<<-1<<endl;
        } else {
            cout<<*it<<endl;
            set.erase(it);
        }
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) {
        cin>>b[j];
    }
    solver(a, b);
    return 0;
}