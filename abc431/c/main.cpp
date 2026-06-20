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
    ll n, m, k;
    cin >> n >> m >> k;
    vll h(n), b(m);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    //rep(i, n) cout << h[i] << endl;
    rep(i, m) cin >> b[i];
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    //rep(i, m) cout << b[i] << endl;
    ll a = 0, c = 0;
    while(a < n && c < m){
        if(h[a] <= b[c]){
            k--;
            a++;
            c++;
        }
        else{
            a++;
        }
    }
    Yn(k <= 0);
    
} 
