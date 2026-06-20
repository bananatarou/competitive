#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int j = 0;
    vector<int> a;
    cin >> N;
    while(N != 1){
        a.push_back(N);
        N = pow(N / 1000, 2) + pow(N % 1000 / 100, 2) + pow(N % 100 / 10, 2) + pow(N % 10, 2);
        
        for (int i = 0; i < j; i++){
            if(N == a[i]){
                cout << "No" << endl;
                return 0;
            }
        }
        
        j++;
    }
    cout << "Yes" << endl;
} 
