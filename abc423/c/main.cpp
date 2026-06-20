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
    ll n, r;
    cin >> n >> r;
    vll l(n + 1);
    l[0] = 0;
    rrep(i, n) cin >> l[i];
    ll i = 1;
    while(i<=n && l[i] == 1){
        i++;
    }
    if(i == n+1){
        cout << 0 << endl;
        return 0;
    }

    ll j = n;
    while(1<=j && l[j] == 1){
        j--;
    }

    ll x = j - i + 1;
    reps(k, i, j+1){
        if(l[k] == 1){
            x++;
        }
    }
    if(r<i){
        x += 2 * (i - r-1);
    }else if(r>j){
        x += 2 * (r - j);
    }

    cout << x << endl;
} 
