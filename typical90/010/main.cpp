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
    ll n, c, p;
    cin>>n;
    vll c1(100001), c2(100001);
    rrep(i, n){
      cin>>c>>p;
      if(c == 1) c1[i] = p;
      else c2[i] = p;
    }
    // 累積和
    vector<int> s1(n+2, 0), s2(n+2, 0); // s[0] = 0 になる
    for (int i = 1; i <= n; ++i){
      s1[i+1] = s1[i] + c1[i];
      s2[i+1] = s2[i] + c2[i];
    }
    ll q, l, r;
    cin>>q;
    rep(i, q){
      cin>>l>>r;
      cout<<s1[r+1] - s1[l]<<' '<<s2[r+1] - s2[l]<<endl;
    }
} 
