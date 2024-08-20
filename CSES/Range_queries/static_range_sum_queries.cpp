#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007
#define INF 1000000000000000000
#define NINF -1000000000000000000
 
// ind-->node
// i-->index updated
 
// SEGMENT TREE
void build(int ind, int low, int high, vector<int>&arr, vector<int>&seg) {
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    // else
 
    int mid = low + (high - low) / 2;
 
    build(2 * ind + 1, low, mid, arr, seg);
    build(2 * ind + 2, mid + 1, high, arr, seg);
 
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    return;
 
}
 
int query(int ind, int low, int high, int l, int r, vector<int>&seg) {
    if (l > high || r < low) return 0;
 
    else if (l <= low && r >= high) return seg[ind];
 
    // else
    int mid = low + (high - low) / 2;
 
    int left = query(2 * ind + 1, low, mid, l, r, seg);
    int right = query(2 * ind + 2, mid + 1, high, l, r, seg);
 
    return left + right;
}
 
 
 
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int>seg(4 * n + 1);
    build(0, 0, n - 1, arr, seg);
 
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(0, 0, n - 1, l, r, seg) << endl;
    }
}
 
 
int32_t main()
{
  solve();
  return 0;
}
