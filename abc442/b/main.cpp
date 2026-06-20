#include<bits/stdc++.h>
using namespace std;

int main() {
    int q, v = 0;
    bitset<1> s("0");
    cin >> q;
    vector<int> a(q);
    for (int i = 0; i < q; i++){
        cin >> a[i];
        if(a[i] == 1){
            v++;
        }else if(a[i] == 2){
            if(v != 0){
                v--;
            }
        }else{
            s = ~s;
        }
        if(v>=3&& s==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
} 
