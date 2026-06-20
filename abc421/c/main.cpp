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
    ll n, j = 0, la = 0, lb = 0, xa = 0, xb = 0;
    cin >> n;
    string s;
    cin >> s;
    while(la < 2 * n){
        if(s[j] == 'A'){
            xa += abs(j - la);
            la += 2;
        }
        j++;
    }
    j = 0;
    while(lb < 2 * n){
        if(s[j] == 'B'){
            xb += abs(j - lb);
            lb += 2;
        }
        j++;
    }
    cout << min(xa, xb) << endl;
} 
