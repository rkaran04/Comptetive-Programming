#include<bits/stdc++.h>
using namespace std;
#define ll long long


// slinding window
int main() {

    string DNA;
    cin >> DNA;

    int l = 0;
    int r = 0;
    int ans = 0;
    while (1) {
        if (r == DNA.size()) {
            ans = max(ans, r - l);
            break;
        }

        if (DNA[r] == DNA[l]) r++;
        else {
            ans = max(ans, r - l);
            l = r;
        }
    }
    cout << ans;

    return 0;
}
