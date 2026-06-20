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



#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

/* alias */
using ull = unsigned long long;
using ll  = long long;
using vi  = vector<int>;

/* short */
#define pb push_back
#define rep(i,n) for (ll i=0;i<(ll)(n);++i)

struct XorShift {
    uint64_t x=88172645463393265ull;
    inline uint64_t next(){ x^=x<<7; x^=x>>9; return x; }
    inline int randint(int l, int r){ // [l, r)
        return (int)(l + (next() % (uint64_t)(r-l)));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,K,T;
    if(!(cin>>N>>M>>K>>T)) return 0;

    vector<vi> g(N);
    rep(i,M){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    // 座標は使わない
    rep(i,N){ int x,y; cin>>x>>y; }

    // 乱数
    XorShift rng;

    // 状態
    int cur = 0;          // 現在位置（開始はショップ0）
    int prev_from = -1;   // 直前の移動元（戻り禁止のため）

    // 最大 T 回、ランダムに移動（行動1のみ）
    // ルール：
    //  - 次の候補は g[cur] のうち prev_from 以外
    //  - 候補が1つも無ければ（理論上ほぼ無いが）prev_from も許可して回避
    for(int step=0; step<T; ++step){
        const auto& nbr = g[cur];
        vector<int> cand;
        cand.reserve(nbr.size());
        for(int v: nbr){
            if(v==prev_from) continue; // 直前戻り禁止
            cand.pb(v);
        }
        if(cand.empty()){
            // 保険：どうしても無ければ prev_from も可に（2-辺連結なので通常は来ない）
            cand = nbr;
        }

        int nxt = cand[rng.randint(0, (int)cand.size())];

        // 出力（移動先）
        cout << nxt << "\n";

        // 状態更新
        int from = cur;
        cur = nxt;
        prev_from = from;

        // 以降の処理は不要：
        //  - 木に入ればコーンに 'W' または 'R' が1文字積まれる
        //  - ショップに入ればその時点のコーンが自動で納品＆空に戻る
        // （いずれもジャッジ側の仕様に従い、こちらは移動先を出すだけでOK）
    }

    return 0;
}

