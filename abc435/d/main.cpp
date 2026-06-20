#include<bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YN(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yn(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define Yn(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)
using Graph = vector<vector<int>>;

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N+1, 0); // 全頂点を「未訪問」に初期化
    int q;
    cin >> q;
    rep(i, q){
        int t, v;
        cin >> t>> v;
        if(t == 1){
            if(dist[v] ==0){
                // BFS 開始 (キューが空になるまで探索を行う)
                queue<int> que;
                dist[v] = 1;
                que.push(v);
                while (!que.empty()) {
                    int v = que.front(); // キューから先頭頂点を取り出す
                    que.pop();

                    // v から辿れる頂点をすべて調べる
                    for (int nv : G[v]) {
                        if (dist[nv] == 0){
                            dist[nv] = 1;
                            que.push(nv);
                        }
                    }
                }
            }
        }else{
            Yn(dist[v]);
        }
    }
}