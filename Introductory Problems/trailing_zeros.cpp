#include<iostream>
using namespace std;

long long trailingzeros(long long n) {
    if(n < 0) return -1;
    long long ans = 0;
    for(long long i = 5; n/i >= 1; i*=5) {
        ans+=n/i;
    }
    return ans;
}
int main() {
    long long n;
    cin>>n;
    cout<<trailingzeros(n);
}