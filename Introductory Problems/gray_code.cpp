#include<iostream>
#include<vector>
#define ll long long
using namespace std;

vector<string> recur(ll n) {
    if(n == 1) {
        vector<string> base;
        base.push_back("0");
        base.push_back("1");
        return base;
    }

    vector<string> rec = recur(n-1);
    vector<string> ans;
    for(int i=0;i<rec.size();i++) {
        string s = "0";
        s += rec[i];
        ans.push_back(s);
    }
    for(int i=rec.size()-1;i >= 0;i--) {
        string s = "1";
        s += rec[i];
        ans.push_back(s);
    }
    return ans;
}

int main() {
    ll n;
    cin>>n;
    vector<string> ans;
    ans = recur(n);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}