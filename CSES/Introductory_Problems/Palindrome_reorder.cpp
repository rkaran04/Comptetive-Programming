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
        string s;
        cin >> s;

        vector<int>count(26, 0);
        for (char ch : s) {
            // cout << ch - 'A' << endl;
            count[int(ch - 'A')]++;
        }
        // for (auto it : count) cout << it << endl;
        int flag = 0;
        int odd = 0;
        char od;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                // cout << i << endl;
                odd++;
                if (odd > 1) {
                    cout << "NO SOLUTION" << endl;
                    flag = 1;
                    break;
                }
                od = char(i + 'A');
                // cout << od << endl;
            }
        }
        if (flag) continue;
        int l = 0;
        int r = s.size() - 1;
        for (int i = 0; i < 26; i++) {
            if (char(i + 'A') != od) {
                for (int it = 0; it < count[i] / 2; it++) {
                    s[l] = char(i + 'A');
                    s[r] = char(i + 'A');
                    l++;
                    r--;
                }
            }
            else {
                int mid = s.size() / 2;
                s[mid] = char(i + 'A');
                for (int it = 1; it <= count[i] / 2; it++) {
                    s[mid - it] = char(i + 'A');
                    s[mid + it] = char(i + 'A');
                }
            }
        }
        cout << s << endl;

    }
    return 0;
}
