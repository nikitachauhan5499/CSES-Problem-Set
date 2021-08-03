#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int count = 1;
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        b[arr[i]-1] = i+1;
    }
    for(int i=1;i<n;i++) {
        if(b[i-1] > b[i]) count++;
    }
    cout<<count<<endl;
    return 0;
}
