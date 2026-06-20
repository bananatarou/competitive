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
    ll n, a, b, sum = 0, r = 0, x = 0;
    cin >> n >> a >> b;
    vll ca(n), cb(n);
    char s;
    rep(i, n){
        cin >> s;
        if(s == 'a'){
            ca[i] = 1;
        }
        else{
            cb[i] = 1;
        }
    }
    vector<pair<ll, ll>> range(n);
    for (int l = 0; l < n; l++){
        while(sum<a && r<n){
            sum += ca[r];
            r++;
        }
        range[l].first = (sum >= a ? r - 1 : n);
        sum -= ca[l];
    }
    sum = 0;
    r = 0;
    for (int l = 0; l < n; l++){
        while(sum<b && r<n){
            sum += cb[r];
            r++;
        }
        range[l].second = (sum >= b ? r - 2 : n-1);
        sum -= cb[l];
    }
    rep(i, n){
        if(range[i].second - range[i].first>= 0){
            x += range[i].second - range[i].first+1;
        }
    }
    //rep(i, n) cout << range[i].first<<range[i].second << endl;
    cout << x << endl;
} 
