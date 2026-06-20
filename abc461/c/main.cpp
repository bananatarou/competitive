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
    ll n, k, m;
    cin >> n >> k >> m;
    vll c(n), v(n);
    rep(i, n) cin >> c[i] >> v[i];
    vector<pair<ll, ll>> vc(n);
    rep(i, n) vc[i] = mp(v[i], c[i]);
    sort(vc.begin(), vc.end()); // {1, 2, 2, 5}
    reverse(vc.begin(), vc.end()); // {5, 2, 2, 1}
    ll nm = 0, sum = 0, nk = 0, i = 0;
    bool cm = 0;
    set<ll> s;
    while(nk!=k){
        if(k -nk == m - s.size()){
            cm = 1;
        }
        if(cm == 1){
            if(!s.count(vc[i].second)){
                s.insert(vc[i].second);
                sum += vc[i].first;
                nk++;
                
            }
        }else{
            s.insert(vc[i].second);
            sum += vc[i].first;
            nk++;
        }
        i++;
    }
    cout << sum << endl;
} 
