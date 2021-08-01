#include<iostream>
#include<vector>
using namespace std;

int solver(int si, int sj, int i, string s, vector<vector<bool> >& vis) {
    if(si < 0 || sj > 6 || sj < 0 || si > 6) return 0;
    if(i == s.length()) return si==6&&sj==0;
    if(si==6 && sj==0) return 0;
    if(vis[si][sj]) return 0;
    vis[si][sj] = 1;
    switch (s[i])
    {
    case 'U':
        return solver(si-1, sj, i+1, s, vis);
        break;
    case 'D':
        return solver(si+1, sj, i+1, s, vis);
        break;
    case 'L': 
        return solver(si, sj-1, i+1, s, vis);
        break;
    case 'R':
        return solver(si, sj+1, i+1, s, vis);
        break;
    default:
        return solver(si-1, sj, i+1, s, vis) + solver(si+1, sj, i+1, s, vis) + solver(si, sj-1, i+1, s, vis) + solver(si, sj+1, i+1, s, vis);
        break;
    }
} 

int main() {
    string s;
    cin>>s;
    vector<vector<bool> > vis(7, vector<bool>(7, 0));
    cout<<solver(0, 0, 0, s, vis)<<endl;
    return 0;
}