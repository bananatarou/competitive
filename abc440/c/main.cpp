#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        long long n, w, s = 0, x, l;
        cin >> n >> w;
        vector<long long> c(n, 0);
        while(c.size() < 4 * w){
            c.push_back(0);
        }
        for (int j = 0; j < n; j++){
            cin >> c[j];
        }
        vector<long long> a(2 * w, 0);
        for (int j = 0; j < n; j++){
            a[(j+1) % (2 * w)] += c[j];
        }
        for (int j = 0; j < w; j++){
            s += a[j];
        }
        x = s;
        l = w;
        for (int j = 0; j < 2 * w - 1; j++){
            if(l >= 2*w){
                l = 0;
            }
            s += a[l] - a[j];
            x = min(x, s);
            l++;
        }
        cout << x << endl;
    }
} 
