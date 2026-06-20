#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int x = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == 'i' || s[i] == 'j'){
            x++;
        }
    }
    cout << x << endl;

} 
