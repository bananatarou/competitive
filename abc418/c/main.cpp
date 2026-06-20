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

int main() {
    #ifdef LOCAL
        freopen("test/sample-1.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q, mx = LONG_LONG_MIN;
    cin >> n >> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, n){
        ll a;
        cin >> a;
        pq.push(a);
        mx = max(mx, a);
    }
    vll b(pow(10, 6) + 1, -1);
    b[1] = 1;
    ll d = n;
    reps(i, 2, pow(10, 6) + 1){
        if(i>mx){
            break;
        }
        b[i] = b[i - 1] + d;
        while(!pq.empty() && pq.top() == i - 1){
            d--;
            pq.pop();
        }
    }
    ll bq;
    rep(i, q){
        cin >> bq;
        cout << b[bq] << endl;
    }
} 
