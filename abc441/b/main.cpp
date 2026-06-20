#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    string s, t;
    cin >> n >> m >> s >> t >> q;
    vector<string> w(q);
    for (int i = 0; i < q; i++){
        cin >> w[i];
        int takan=0, aon=0;
        for (int j = 0; j < w[i].size(); j++){
            for (int k = 0; k < n; k++){
                if (w[i][j] == s[k]){
                    takan++;
                }
            } 
            for (int k = 0; k < m; k++){
                if (w[i][j] == t[k]){
                    
                    aon++;
                }
            }
        }
        
        if (takan == w[i].size() && aon == w[i].size()){
            cout << "Unknown" << endl;
        }else if(aon == w[i].size()){
            cout << "Aoki" << endl;
        }else{
            cout << "Takahashi" << endl;
        }
    }
} 
