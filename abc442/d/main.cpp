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

int main() {
    ll n, q, k, x, l, r;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> s(n+1, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        s[i + 1] = s[i] + a[i];
    }
    rep(i, q){
        cin >> k;
        if (k == 1){
            cin >> x;
            s[x] += a[x] - a[x - 1];
            swap(a[x - 1], a[x]);
        }else{
            cin >> l >> r;
            cout << s[r] - s[l-1] << endl;
        }
    }
} 