#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector <long long> a(m), b(m), c(n + 1, n - 1);
    for (int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++){
        c[a[i]]--;
        c[b[i]]--;
    }
    for (int i = 1; i <= n; i++){
        if(c[i] >= 3){
            if(i != n){
                long long x = c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                cout <<  x<< " ";
            }else{
                long long x = c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                cout << x << endl;
                
            }
        }else{
            if(i != n){
                cout << 0 << " ";
            }else{
                cout << 0 << endl;
                
            }
        }
    }
}

