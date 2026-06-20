#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N+1);
    vector<int> x;
    for (int i = 1; i * i<=N; i++){
        for (int j = i + 1; i * i + j * j <= N; j++){
            a[i * i + j * j]++;
        }
    }
    for (int i = 1; i <= N; i++){
        if(a[i] == 1){
            x.push_back(i);
        }
    }
    cout << x.size() << endl;
    if(x.size() != 0){
        cout << x[0];
    }
    for (size_t i = 1; i < x.size(); i++){
        cout <<  ' ' << x[i];
    }
    cout << endl;
} 
