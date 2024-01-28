#define ll long long
using namespace std;
 
int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        ll n;
        cin >> n;
   // simple formula applies to all n>=4
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                cout << 0 << endl;
            }
            else if (i == 2) {
                cout << 6 << endl;
            }
            else if (i == 3) {
                cout << 28 << endl;
            }
            else {
                ll tot = i * i;
                tot = tot * (tot - 1);
                tot = tot >> 1;
                ll x = i - 4;
                ll y = x * x;
                ll del = 4 * (y + 5 * x + 6);
                cout << tot - del << endl;
            }
        }
    }
    return 0;
