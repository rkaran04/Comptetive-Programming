#include<iostream>
#define ll long long
using namespace std;
 
int main()
{
    int t = 1;
   
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 4) {
            cout << 2 << " " << 4 << " " << 1 << " " << 3; //for n=4, the general solution below wont work
            continue;
        }
        if (n == 2 || n == 3) {
            cout << "NO SOLUTION" << endl;
            continue;
        }
 
        int l = 2;
        int r = ((n + 1) / 2) + 1;
        cout << 1;
        for (int i = 1; i < n; i++) {
 
            if (i % 2 == 0) {
                cout << " " << l;
                l++;
            }
            else {
                cout << " " << r;
                r++;
            }
        }
 
    }
    return 0;
}
