#include<iostream>
#include<set>
#include<vector>
#include<iterator>
using namespace std;

void longestpassage(vector<int> arr, int x) {
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ms;
    ms.insert(x);
    for(int i=0;i<arr.size();i++) {
        s.insert(arr[i]);
        auto it = s.find(arr[i]);
        int p = *prev(it);
        int n = *next(it);
        ms.erase(ms.find(n-p));
        ms.insert(arr[i]-p);
        ms.insert(n-arr[i]);
        cout<<*ms.rbegin()<<endl;
    }
}

int main() {
    int x, n;
    cin>>x>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    longestpassage(arr, x);
    return 0;
}