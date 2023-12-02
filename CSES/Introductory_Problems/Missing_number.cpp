#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
// Take XOR of all numbers 1-n, then take input of n-1 numbers and do their XOR, existing numbers cancel, ans remains as sum
int main() {
 
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum ^= i;
 
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        sum ^= a;
    }
    cout << sum;
 
 
    return 0;
}
