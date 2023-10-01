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
	// cin >> test;
	test = 1;

	for (int t = 0; t < test; t++) {

		int m, n;
		cin >> m >> n;

		vector<int>row(m, -1); // to mark rows which dont have 1
		vector<int>col(n, -1); // to mark cols which dont have 1

		vector<vector<int>>B(m, vector<int>(n, 0));
		int flag = 0; //to check for mistake

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;

				if (x == 0) {
					row[i] = 1;
					col[j] = 1;
				}
				if (x == 1) {
					B[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				//checking for mistakes
				if (B[i][j] == 1 && row[i] == 1 && col[j] == 1) flag = 1;
				if (B[i][j] == 0 && (row[i] == -1 || col[j] == -1)) flag = 1;

			}
		}
		//one mistake: if only row or col has elements marked -1.
		//we should always be able to pair a row with -1 and col with -1
		int count = 0;
		for (auto it : row) if (it == -1) {
				count++;
				break;
			}
		for (auto it : col) if (it == -1) {
				count++;
				break;
			}

		if (count % 2 == 1) flag = 1;

		//output
		if (flag == 1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (row[i] == 1	|| col[j] == 1) B[i][j] = 0;
					else B[i][j] = 1;
				}
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n - 1; j++) {
					cout << B[i][j] << " ";
				}
				cout << B[i][n - 1] << endl;
			}
		}


	}



	//end code
}
