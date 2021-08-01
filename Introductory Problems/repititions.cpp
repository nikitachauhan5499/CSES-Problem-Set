#include<iostream>
#define ll long long
using namespace std;

int main() {
    string s;
    cin>>s;
    unsigned int i = 0;
    int maxi = 1;
    while(i < s.length()) {
        int a = 0, c = 0, g = 0, t = 0;
        while(i < s.length() && s[i] == 'A') {
            i++;
            a++;
        }
        maxi = max(a, maxi);
        while(i < s.length() && s[i] == 'C') {
            i++;
            c++;
        }
        maxi = max(c, maxi);
        while(i < s.length() && s[i] == 'G') {
            i++;
            g++;
        }
        maxi = max(g, maxi);
        while(i < s.length() && s[i] == 'T') {
            i++;
            t++;
        }
        maxi = max(t, maxi);

    }
    cout<<maxi<<endl;
    return 0;
}