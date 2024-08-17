#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// ind-->node
// i-->index updated


class SGTree {
    // ---------------global segment tree array---------------
    vector<int>seg;


public:
    // ---------------constructor-----------------
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    // ---------------build function---------------
    void build(int ind, int low, int high, vector<int>&arr) {
        // base case

        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        // recursion

        int mid = low + ((high - low) >> 1);

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        return;
    }



    // ---------------query----------------------
    int query(int ind, int low, int high, int l, int r) {
        // no overlap
        if (low > r || high < l) return INF;

        // complete overlap
        else if (l <= low && high <= r) return seg[ind];

        // partial overal
        else {
            int mid = low + ((high - low) >> 1);
            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1,  high, l, r);
            return min(left, right);
        }
    }


    // ---------------update---------------------
    void update(int ind, int low, int high, int i, int val) {
        // base case

        if (low == high) {
            seg[ind] = val;
            return;
        }

        // recursion

        int mid = low + ((high - low) >> 1);

        if (i <= mid) update(2 * ind + 1,  low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        return;
    }

};

void solve() {
    int n;
    cin >> n ;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SGTree sg(n);

    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            cout << sg.query(0, 0, n - 1, l, r) << endl;
        }
        else {
            int i, val;
            cin >> i >> val;
            arr[i] = val;
            sg.update(0, 0, n - 1, i, val);
        }
    }
}


int32_t main()
{

    int t ;
    // cin >> t;
    t = 1;
    for (int T = 0; T < t; T++) {

        solve();
    }
    return 0;
}
