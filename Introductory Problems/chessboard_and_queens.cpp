#include<iostream>
#include<vector>
using namespace std;
int q = 8;
bool isSafe(vector<vector<char> > v, int i, int j) {
    if(i == 0) return 1;
    for(int k=i-1;k>=0;k--) {
        if(v[k][j] == 'Q') return 0;
    }
    for(int k=i-1, l=j-1;k>=0 && l>=0;k--, l--) {
        if(v[k][l] == 'Q') return 0; 
    }
    for(int k=i-1, l=j+1;k>=0 && l<q;k--, l++) {
        if(v[k][l] == 'Q') return 0;
    }
    return 1;
}

int noofways(vector<vector<char> >& v, int i) {
    if(i == q) {
        return 1;
    }
    int ans = 0;
    for(int j=0;j<q;j++) {
        if(v[i][j] == '.' && isSafe(v, i, j)) {
            v[i][j] = 'Q';
            ans+=noofways(v, i+1);
            v[i][j] = '.';
        }
    }
    return ans;
}

int main() {
    vector<vector<char> > v(q, vector<char>(q));
    for(int i=0;i<q;i++) {
        for(int j=0;j<q;j++) {
            cin>>v[i][j];
        }
    }
    cout<<noofways(v, 0)<<endl;
    return 0;
}