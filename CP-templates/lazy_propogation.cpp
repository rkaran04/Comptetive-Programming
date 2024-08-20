#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000

// ind-->node
// i-->index updated


// this code is written for range sum queries where update queries are over a range. 

class SGT {
public:


    vector<int>seg;
    vector<int>lazy;


    SGT(int n) {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0);
    }


    void build(int ind, int low, int high, vector<int>&arr) {
        // reached a leaf node
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        // non-leaf node
        int mid = low + (high - low) / 2;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
        return;
    }



    int query(int ind, int low, int high, int l, int r) {

        // update if anything in lazy nodes
        if (lazy[ind] != 0) {
            seg[ind] += lazy[ind] * (high - low + 1);


            // propogate waht we added to  the children for the downwards nodes to get updated
            // check if children present: low!=high
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        if (l > high || low > r) return 0;

        // complete overlap
        else if (l <= low && high <= r) return seg[ind];

        // partial overlap
        else {
            int mid = low + (high - low) / 2;

            int left = query(2 * ind + 1, low, mid, l, r);
            int right = query(2 * ind + 2, mid + 1, high, l, r);

            return left + right;

        }
    }



    void update(int ind, int low, int high, int l, int r, int val) {

        // update if anything in lazy nodes
        if (lazy[ind] != 0) {
            seg[ind] += lazy[ind] * (high - low + 1);


            // propogate waht we added to  the children for the downwards nodes to get updated
            // check if children present: low!=high
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        if (l > high || low > r) return;


        // complete overlap
        else if (l <= low && high <= r) {

            seg[ind] += val * (high - low + 1);

            // propogate val to children, check if children present: low!=high
            if (low != high) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        // partial overlap
        else {
            int mid = low + (high - low) / 2;

            update(2 * ind + 1, low, mid, l, r, val);
            update(2 * ind + 2, mid + 1, high, l, r, val);

            seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
            return;
        }

    }
};


void solve() {
    int n, q;
    cin >> n >> q;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SGT sgt(n);

    sgt.build(0, 0, n - 1, arr);

    while (q--) {
        int type;
        cin >> type;
        // type = 2;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            sgt.update(0, 0, n - 1, l, r, val);

        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << sgt.query(0, 0, n - 1, l, r) << endl;
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
