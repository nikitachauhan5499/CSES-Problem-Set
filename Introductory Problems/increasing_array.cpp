#include<iostream>
#define ll long long
using namespace std;

ll arr[200000];

int main() {
    ll n;
    cin>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll count = 0;
    for(ll i=1;i<n;i++) {
        if(arr[i] - arr[i-1] < 0) {
            count += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }
    cout<<count<<endl;
    return 0;
}