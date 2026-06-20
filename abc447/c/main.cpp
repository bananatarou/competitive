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
    string s, t, nas, nat;
    cin >> s >> t;
    rep(i, s.size()){
        if(s[i] != 'A'){
            nas += s[i];
        }
    }
    rep(i, t.size()){
        if(t[i] != 'A'){
            nat += t[i];
        }
    }
    if(nas != nat){
        cout << -1 << endl;
        return 0;
    }
    ll si = 0, ti = 0, x = 0;
    ll ss = s.size();
    ll ts = t.size();
    while(!(si == ss - 1 || ti == ts - 1)){
        if(s[si] != t[ti]){
            if(s[si] == 'A'){
                si++;
                x++;
            }else{
                ti++;
                x++;
            }
        }else{
            si++;
            ti++;
        }
        /*
        cout << si << endl
             << ti << endl
             << x << endl;
        */
    }
    x += ss - 1 - si;
    x += ts - 1 - ti;
    cout << x << endl;
} 
