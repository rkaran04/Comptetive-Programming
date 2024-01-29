#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

int main()
{
    int t ;
    cin >> t;
    // t = 1;
    for (int j = 0; j < t; j++) {
        ll a, b;
        cin >> a >> b;

        if ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
