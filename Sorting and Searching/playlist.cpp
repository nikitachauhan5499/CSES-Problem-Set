#include<bits/stdc++.h>
using namespace std;

int playlist(vector<int> arr) {
    int i=0, j=0, maxi = 0;
    set<int> s;
    while(j < arr.size()) {
        while(j<arr.size() && s.find(arr[j]) == s.end()) {
            s.insert(arr[j]);
            j++;
        }
        if(maxi < s.size())
            maxi = s.size();
        while(i < j && s.find(arr[j]) != s.end()) {
            s.erase(arr[i]);
            i++;
        }
    }
    return maxi;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<playlist(arr)<<endl;
    return 0;
}