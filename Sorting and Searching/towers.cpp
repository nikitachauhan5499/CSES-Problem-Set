#include<bits/stdc++.h>
#define ll long long
using namespace std;

int towers(vector<int> arr) {
    multiset<int> s;
    for(int i=0;i<arr.size();i++) {
        auto it = s.upper_bound(arr[i]);
        if(it == s.end()) {
            s.insert(arr[i]);
        } else {
            s.erase(it);
            s.insert(arr[i]);
        }
    }
    return s.size();
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<towers(arr);
    return 0;
}