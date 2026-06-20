#include<bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

/* alias */
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
using vs = vector<string>;



/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define YN(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yn(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define Yn(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define endl '\n'

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

template<class T> inline bool chmin(T & a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T & a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using Graph = vector<vector<int>>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 頂点数と辺数、s と t
    int N, M, s, t, ans = 0; cin >> N >> M;
    s = 1;
    

    // グラフ入力受取
    Graph G(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 頂点 s をスタートとした探索
    vector<int> dist(N+1, -1);
    queue<int> que;
    dist[s] = 0, que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    // t に辿り着けるかどうか
    reps(i, 1,  N+1){
        if(dist[i] != -1){
            ans++;
        }
    }
    cout<<ans<<endl;
} 
