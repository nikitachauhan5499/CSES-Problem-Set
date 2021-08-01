#include<bits/stdc++.h>
using namespace std;
 
void printallpossible(string ques, string ans, set<string>& out) {
    if(ques.length() == 0) {
        out.insert(ans);
        return;
    }
 
    for(int i=0;i<ques.length();i++) {
        string left = ques.substr(0, i);
        string right = ques.substr(i+1);
        printallpossible(left+right, ans+ques[i], out);
    }
}
 
int main() {
    string s;
    cin>>s;
    set<string> se;
    printallpossible(s, "", se);
    cout<<se.size()<<endl;
    for(auto ch: se) cout<<ch<<endl;
    return 0;
}