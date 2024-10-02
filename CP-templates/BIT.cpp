class BITree {
    vector<int>bit;
    int size;
public:
    BITree(int n) {
        bit.resize(n + 1, 0);
        size = n;
    }

    // update all intervals that have i by the value to be added
    //logN
    void update(int i, int add) {
        while (i <= size) {
            bit[i] += add;
            i = i + (i & (-i));
        }
    }

    // prefix sum
    // logN
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i = i - (i & (-i));
        }
        return s;
    }

    int rangesum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    BITree bit(n);

    for (int i = 1; i <= n; i++) {
        bit.update(i, arr[i - 1]);
    }



    while (q--) {
        int type;
        cin >> type;
        // type = 2;
        if (type == 1) {
            int i, val;
            cin >> i >> val;
            val = val - arr[i - 1];
            arr[i - 1] += val;
            bit.update(i, val);

        }
        else {
            int l, r;
            cin >> l >> r;
            cout << bit.rangesum(l, r) << endl;
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
