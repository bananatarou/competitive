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
    ll n;
    cin >> n;
    vll a(n + 2);
    a[0] = LLONG_MIN;
    a[n + 1] = LLONG_MAX;
    rrep(i, n) cin >> a[i];
    
    ll q;
    cin >> q;
    vector<tuple<ll, ll, ll>> b(q);
    rep(i, q){
        cin >> get<0>(b[i]);
        get<1>(b[i]) = i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll j = 0;
    rep(i, q){
        while(j <= n+1){
            if(get<0>(b[i]) > a[j]){
                j++;
            }else if(get<0>(b[i]) == a[j]){
                get<2>(b[i]) = 0;
                break;
            }else{
                get<2>(b[i]) = min(abs(get<0>(b[i]) - a[j-1]), abs(get<0>(b[i]) - a[j]));
                break;
            }
        }
    }
    rep(i, q){
        b[i] = make_tuple(get<1>(b[i]), get<0>(b[i]), get<2>(b[i]));
    }
    sort(b.begin(), b.end());
    rep(i, q){
        cout << get<2>(b[i]) << endl;
    }
} 
