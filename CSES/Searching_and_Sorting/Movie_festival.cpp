#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007
 
 
 
int main()
{
    int t ;
    // cin >> t;
    t = 1;
    for (int j = 0; j < t; j++) {
        int n;
        cin >> n;
        vector<pair<ll, ll>>time;
 
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            time.push_back({b, a});
 
        }
        sort(time.begin(), time.end());
 
        int movies = 0;
 
        ll finish = 0;
        for (int i = 0; i < n; i++) {
            if (time[i].second >= finish) {
                movies++;
                finish = time[i].first;
            }
        }
        cout << movies << endl;
    }
    return 0;
}
