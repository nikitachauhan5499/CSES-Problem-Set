#include<iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    int alph[26] = {0};
    for(int i=0;i<s.length();i++) {
        alph[s[i]-'A']++;
    }
    int odd = 0;
    char ch = '-';
    for(int i=0;i<26;i++) {
        if(alph[i]%2 == 1) {
            odd++;
        }
    }
    if(s.length()%2 == 0 && odd != 0 || s.length()%2 == 1 && odd != 1) cout<<"NO SOLUTION"<<endl;
    else {
        int i=0, j=s.length()-1;
        for(int k=0;k<26;) {
            if(alph[k] == 1 || alph[k] == 0) {
                if(alph[k] == 1) {
                    s[s.length()/2] = k+'A';
                    alph[k]--;
                }
                k++;
                continue;
            }
            s[i] = k+'A';
            s[j] = k+'A';
            i++;
            j--;
            alph[k]-=2;
        }
        cout<<s<<endl;
    }
    return 0;
    
}