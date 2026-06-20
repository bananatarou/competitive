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
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int H, W;
vector<string> field;
bool seen[1010][1010]; // seen[h][w] := マス (h, w) が検知済みかどうか
void dfs(int h, int w) {
    seen[h][w] = true;

    // 四方向を探索
    for (int dir = 0; dir < 4; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;

        // 再帰的に探索
        dfs(nh, nw);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 入力受け取り
    cin >> H >> W;
    field.resize(H);
    for (int h = 0; h < H; ++h) cin >> field[h];
    
    rep(w, W){
        if(field[0][w] == '#') continue;
        dfs(0, w);
    }
    rep(w, W){
        if(field[H-1][w] == '#') continue;
        dfs(H-1, w);
    }
    rep(h, H){
        if(field[h][0] == '#') continue;
        dfs(h, 0);
    }
    rep(h, H){
        if(field[h][W-1] == '#') continue;
        dfs(h, W-1);
    }
    // 探索開始
    int count = 0;
    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (seen[h][w] == 1) continue; // 残島じゃなかったらスルー
            if(field[h][w] == '#') continue;
            dfs(h, w);
            ++count;
        }
    }
    cout << count << endl;
}
