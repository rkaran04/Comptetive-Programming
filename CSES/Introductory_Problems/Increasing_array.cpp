#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main() {

    int n;
    cin >> n;

    int a = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < a) ans += a - x;
        else a = x;
    }
    cout << ans;
    return 0;
}
