#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin>>n;
    ll ans;
    if(n%2 == 0) {
        ans = (n/2)*(n+1);
    } else {
        ans = ((n+1)/2)*(n);
    }
    vector<ll> s1, s2; 
    string choice = "NO";
    if(ans%2 == 0) {
        ll target = ans/2;
        choice = "YES";
        if(target%n != 0) {
            ll k = 0;
            ll start = 1, end = n;
            while(k+start+end <= target) {
                k+=start;
                k+=end;
                s1.push_back(start);
                s1.push_back(end);
                start++;
                end--;
            }
            for(ll i=start;i<=end;i++) s2.push_back(i);
        } else {
            ll start = 1, end = n;
            s1.push_back(end);
            ll k = end;
            end--;
            while(start+end+k <= target) {
                k+=(start+end);
                s1.push_back(start);
                s1.push_back(end);
                start++;
                end--;
            }
            for(ll i=start;i<=end;i++) s2.push_back(i);
        }
        sort(s1.begin(), s1.end());
        cout<<choice<<endl;
        cout<<s1.size()<<endl;
        for(ll i=0;i<s1.size();i++) cout<<s1[i]<<" ";
        cout<<endl<<s2.size()<<endl;
        for(ll i=0;i<s2.size();i++) cout<<s2[i]<<" ";
    } else {
        cout<<choice<<endl;
    }
    return 0;
}