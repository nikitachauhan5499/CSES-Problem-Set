#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<string> str(n);
    for(int i=0;i<n;i++) {
        cin>>str[i];
    }
    vector<vector<int> > dp(n+1, vector<int>(n+1));
    dp[1][1] = str[0][0] == '.'? 0 : 1;

    // prefix sum row
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i == 1 && j == 1) {
                dp[i][j] = 0;
            } else 
                dp[i][j] += dp[i][j-1];
            if(str[i-1][j-1] == '*') dp[i][j]++;
        }
    }
    
    //prefix sum col
    for(int j=1;j<=n;j++) {
        for(int i=1;i<=n;i++) {
            dp[i][j] += dp[i-1][j];
        }
    }

    for(int i=0;i<q;i++) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        long long ans = 0;
        ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout<<ans<<endl;
    }
    return 0;
}