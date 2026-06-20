#include<bits/stdc++.h>
using namespace std;

int main() {
    int p, q, x, y;
    cin >> p >> q >> x >> y;
    if(x >= p && x < 100+p && y>=q&&y<100+q){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
} 
