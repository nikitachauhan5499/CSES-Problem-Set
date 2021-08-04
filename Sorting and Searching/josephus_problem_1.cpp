#include<iostream>
#include<vector>
using namespace std;

vector<int> josephus(int n, int l) {
    vector<int> ans;
    vector<bool> vis(n);
    int kill = 0, k = 1, i = 0;
    while(kill < n) {
        if(vis[i]) {
            i++;
            i%=n;
            continue;
        }
        if(k == l) {
            if(!vis[i]) {
                vis[i] = 1;
                k = 1;
                kill++;
                ans.push_back(i+1);
            }
        } else {
            k++;
        }
        i++;
        i%=n;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> ans = josephus(n, 2);
    for(auto it: ans) {
        cout<<it<<" ";
    }
    return 0;
}