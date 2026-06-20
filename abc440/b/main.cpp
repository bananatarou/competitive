#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++){
        a[i].second = i + 1;
        cin >> a[i].first;
    }
    sort(a.begin(), a.end());
    cout << a[0].second<<' '<< a[1].second <<' '<< a[2].second << endl;
} 
