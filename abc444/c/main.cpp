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
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(all(a));
    ll i = a.size() - 2;
    while(a[i] == a.back()){
        i--;
    }
    bool f = 1, g = 1;
    if((i + 1) % 2 ==0){
        rep(j, (i + 1) / 2){
            if(a[j] + a[i] != a.back()){
                f = 0;
                break;
            }
            i--;
        }
    }else{
        f = 0;
    }
    
    if(a.size() % 2 == 0){
        rep(j, (a.size() + 1) / 2){
            if(a[j] + a[a.size() - 1 - j] != a[0] + a[a.size() - 1]){
                g = 0;
                break;
            }
        }        
    }else{
        g = 0;
    }
    if(f == 1 && g == 1){
        cout << a.back() << " " << a[0] + a[a.size() - 1] << endl;
    }else if(f == 1 && g == 0){
        cout << a.back() << endl;
    }else{
        cout << a[0] + a[a.size() - 1] << endl;
    }
} 
