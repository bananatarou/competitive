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

vvll a(2000, vll(2000));
int main() {
    ll h, w;
    cin >> h >> w;
    //vvll a(h, vll(w));
    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }
    vll sumh(w, 0), sumw(h, 0);
    rep(i, w){
        rep(j, h){
            sumh[i] += a[j][i];
        }
    }
    rep(i, h){
        rep(j, w){
            sumw[i] += a[i][j];
        }
    }
    rep(i, h){
        rep(j, w - 1){
            cout << sumh[j] + sumw[i] - a[i][j] << ' ';
        }
        cout << sumh[w-1] + sumw[i] - a[i][w-1] << endl;
    }
} 
