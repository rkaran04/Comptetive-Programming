#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// input output
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	// input output



	// start code

	int test;
	cin >> test;
	// test = 1;

	for (int t = 0; t < test; t++) {

		ll n, m, r;
		cin >> n >> m >> r;
		// ll ans = 0;
		ll sum_n = 0;
		ll h_n = 0;
		ll l_n = 1e9;
		ll sum_m = 0;
		ll h_m = 0;
		ll l_m = 1e9;

		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;

			sum_n += x;
			h_n = max(h_n, x);
			l_n = min(l_n, x);

		}
		for (int i = 0; i < m; i++) {
			ll x;
			cin >> x;

			sum_m += x;
			h_m = max(h_m, x);
			l_m = min(l_m, x);

		}

		if (l_n < h_m) {
			sum_n = sum_n - l_n + h_m;
			h_n = max(h_n, h_m);
			l_m = min(l_m, l_n);
		}
		if (!(r & 1)) {
			if (h_n > l_m) {
				sum_n = sum_n - h_n + l_m;
			}
		}
		cout << sum_n << endl;



	}

	//end code
}
