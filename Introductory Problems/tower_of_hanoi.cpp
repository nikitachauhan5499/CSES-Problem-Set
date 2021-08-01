#include<iostream>
#include<math.h>
using namespace std;

void toh(int n, int src, int help, int dest) {
    if(n<=0) return;
    toh(n-1, src, dest, help);
    cout<<src<<" "<<dest<<endl;
    toh(n-1, help, src, dest);
}

int main() {
    int n;
    cin>>n;
    int moves=0;
    cout<<pow(2, n) - 1<<endl;
    toh(n, 1, 2, 3);
    return 0;
}