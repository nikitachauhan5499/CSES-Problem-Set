#include<iostream>
#include<vector>
#include<math.h>
#define ll long long
using namespace std;

ll sqr[400004];

void preprocess(vector<ll>& hotels) {
    ll n = hotels.size();
    ll len = sqrt(n);
    if(len*len != n) len++;
    for(ll i=0;i<n;i++) {
        if(i%len  == 0) {
            sqr[i/len] = i;
        } else {
            if(hotels[sqr[i/len]] < hotels[i]) sqr[i/len] = i;
        }
    }
}

ll find(ll q, ll start, ll len, vector<ll>& hotels) {
    ll n = hotels.size();
    ll j = 0;
    while(j<len) {
        if(j == n) return 0;
        if(hotels[start*len+j] >= q) {
            hotels[start*len+j]-=q;
            return start*len+j;
        }
        j++;
    }
    return 0;
}

void updateAfterProcessing(ll start, ll len, vector<ll>& hotels) {
    ll j = 1;
    ll n = hotels.size();
    sqr[start] = start*len;
    while(j < len) {
        if(j == n) return;
        if(hotels[sqr[start]] < hotels[start*len+j]) {
            sqr[start] = start*len+j;
        }
        j++;
    }
}

ll getAnswer(vector<ll>& hotels, ll q) {
    ll ans = -1;
    ll n = hotels.size();
    ll len = sqrt(n);
    if(len*len != n) len++;
    for(ll i=0;i<len;i++) {
        if(hotels[sqr[i]] < q) continue;
        ans = find(q, i, len, hotels);
        updateAfterProcessing(i, len, hotels);
        break;
    }
    return ans+1;

}

void hotelQueries(vector<ll>& hotels, vector<ll>& queries) {
    ll n, m;
    n = hotels.size(), m = queries.size();
    preprocess(hotels);
    for(ll i=0;i<m;i++) {
        cout<<getAnswer(hotels, queries[i])<<endl;
    }
}

int main() {
    ll n, m;
    cin>>n>>m;
    vector<ll> hotels(n);
    for(ll i=0;i<n;i++) cin>>hotels[i];
    vector<ll> queries(m);
    for(ll i=0;i<m;i++) cin>>queries[i];
    hotelQueries(hotels, queries);
    return 0;
}