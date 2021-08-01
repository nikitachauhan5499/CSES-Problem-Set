#include<iostream>
using namespace std;

int arr[200001];
int pre[200001];

int main() {
    int n, q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];
    pre[0] = arr[0];
    for(int i=1;i<n;i++) {
        pre[i] = pre[i-1] ^ arr[i];
    }
    for(int i=0;i<q;i++) {
        int a, b;
        cin>>a>>b;
        if(a==1) {
            cout<<pre[b-1]<<endl;
        } else {
            int ans = pre[b-1]^pre[a-2];
            cout<<ans<<endl;
        }
    }
    return 0;
}