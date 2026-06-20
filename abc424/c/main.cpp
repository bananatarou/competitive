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
    vvi g(n + 1);
    set<ll> s;
    queue<ll> q;
    vector<bool> bo(n + 1);
    rrep(i, n){
        ll a, b;
        cin >> a >> b;
        if(a == 0 && b == 0){
            s.insert(i);
            bo[i] = 1;
            q.push(i);
        }else{
            g[a].pb(i);
            g[b].pb(i);
        }
    }
    while(!q.empty()){
        ll f = q.front();
        q.pop();
        for(auto&& a : g[f]){
            if(bo[a] == 0){
                s.insert(a);
                bo[a] = 1;                
                q.push(a);
            }
        }
    }

    cout << s.size() << endl;
} 
