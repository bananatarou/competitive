#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, k,x, t = 0;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n-k; i++){
        a[i] = 0;
    }
    while(x>0 && t<n){
        x -= a[t];
        t++;
    }
    if(x <= 0){
        cout<< t << endl;
    }else{
        cout << -1 << endl;
    }
    
} 
