#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        long long n, ws = 0, j;
        cin >> n;
        vector<long long> w(n), p(n), wp(n);
        for (j = 0; j < n; j++){
            cin >> w[j] >> p[j];
            wp[j] = w[j] + p[j];
            ws += w[j];
        }
        sort(wp.rbegin(), wp.rend());
        for (j = 0; ws > 0; j++){
            ws -= wp[j];
        }
        cout << n - j << endl;
    }
}