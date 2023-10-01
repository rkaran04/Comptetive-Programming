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

		int n;
		cin >> n;

		int l = 0;
		int r = 0;

		for (int i = 0; i < n; i++) {
			char x;
			cin >> x;
			if (x == '1') {
				if (l == 0) l = i + 1;
				else r = i + 1;
			}
		}

		if (l == 0) {
			cout << n << endl;
		}
		else if (r == 0) {
			cout << 2 * max(l, n - l + 1) << endl;
		}
		else if (l > n - r + 1) {
			cout << 2 * r << endl;
		}
		else {
			cout << 2 * (n - l + 1) << endl;
		}


	}

	//end code
}
