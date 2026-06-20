#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++){
        cin >> B[i];
    }
    vector<int> C(H, 0);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            for (int k = 0; k < N; k++){
                if (A[i][j] == B[k]) {
                    C[i]++;
                }
            }
        }
    }
    int max = *max_element(C.begin(), C.end());
    cout << max << endl;
} 
