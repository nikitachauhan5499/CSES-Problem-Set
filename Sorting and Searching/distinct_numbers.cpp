#include<bits/stdc++.h>
using namespace std;

int distinctnumbers(int n, vector<int> arr) {
    set<int> s;
    for(int i=0;i<n;i++) s.insert(arr[i]);
    return s.size();
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<distinctnumbers(n, arr);
    return 0;
}