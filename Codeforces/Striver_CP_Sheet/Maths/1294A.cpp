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
		int a, b, c, n;
		cin >> a >> b >> c >> n;

		vector<int>arr = {a, b, c};
		sort(arr.begin(), arr.end());

		if (arr[0] < arr[1]) {
			n -= arr[1] - arr[0];
			if (n < 0) {
				cout << "NO" << endl;
				continue;
			}
		}
		if (arr[1] < arr[2]) {
			n -= 2 * (arr[2] - arr[1]);
			if (n < 0) {
				cout << "NO" << endl;
				continue;
			}
		}
		if (n % 3 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	//end code
}
