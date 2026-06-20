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


// Pythonと同じ動きの剰余演算
#define pydiv(a,b) ((0<=((a)^(b))) ? (a)/(b) : (0<(b)) ? ((a)-(b)+1)/(b) : ((a)-(b)-1)/(b))
// Pythonと同じ動きの除算
#define pymod(a,b) ((0<=((a)^(b))) ? (a)%(b) : ((a)%(b)+(b))%(b))

int main() {
    int n, r, c, k;
    cin >> n;
    vvl a(n, vl(n));
    r = 0;
    c = (n - 1) / 2;
    k = 1;
    a[r][c] = k;

    rep(i, n * n - 1){
        k++;
        if (a[pymod((r - 1) , n)][pymod((c + 1) , n)] == 0){
            c = pymod((c + 1) , n);
            r = pymod((r - 1) , n);
            a[r][c] = k;
        }else{
            r = pymod((r + 1) , n);
            a[r][c] = k;
        }
    }
    rep(i, n){
        rep(j, n){
            if(j != 0){
                cout << " ";
            }
            cout << a[i][j];
            if(j == n-1){
                cout << endl;
            }
        }
    }
} 
