#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ferriswheel(vector<int> arr, int x) {
    sort(arr.begin(), arr.end());
    int i=0, j = arr.size()-1, count=0;
    while(i < j) {
        if(arr[i] + arr[j] > x) {
            j--;
        } else {
            i++;
            j--;
        }
        count++;
    }
    if(i == j) count++;
    return count;
}

int main() {
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<ferriswheel(arr, x)<<endl;
    return 0;
}