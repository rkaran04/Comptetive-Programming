#include<bits/stdc++.h>
#define ll long long
using namespace std;

// trick: n*n square has n*n elements. so 3*3 has 1-9.
int main()
{
    int t ;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll r, c;
        cin >> r >> c;
 
        ll x = max(r, c) - 1;
 
        if (x % 2 == 0) {
            if (r < c) {
                cout << (x + 1)*(x + 1) - r + 1 << endl;
            }
            else cout << x*x + c << endl;
        }
        else {
            if (r > c) {
                cout << (x + 1)*(x + 1) - c + 1 << endl;
            }
            else cout << x*x + r << endl;
        }
 
    }
    return 0;
}
