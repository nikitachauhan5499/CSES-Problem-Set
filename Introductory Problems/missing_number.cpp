#include<iostream>
#define ll long long
using namespace std;

int arr[200001];
int main() {
    ll n;
    cin>>n;
    ll sum = 0;
    for(int i=0;i<n-1;i++) {cin>>arr[i]; sum+=arr[i];}
    ll k = (n)*(n+1)/2;
    ll mn = k-sum;
    cout<<mn<<endl;
    return 0;
}