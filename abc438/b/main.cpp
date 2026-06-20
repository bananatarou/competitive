#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sum, x = 2147483647;
    cin >> n >> m;
    vector<char> cs(n), ct(n);
    vector<int> s(n), t(n);
    for (int i = 0; i < n; i++){
        cin >> cs[i];
        s[i] = cs[i] - 48;
    }
    for (int i = 0; i < m; i++){
        cin >> ct[i];
        t[i] = ct[i] - 48;
    }
    for (int i = 0; i < n - m + 1; i++){
        sum = 0;
        for (int j = i; j < i + m; j++){
            if(s[j] >= t[j-i]){
                sum += s[j] - t[j-i];
            }else{
                sum += 10 - t[j-i] + s[j];
            }
            
        }
        
        x = min(x, sum);
    }
    cout << x << endl;
} 
