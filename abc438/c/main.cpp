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
    int n, c=0;
    cin >> n;
    vector<int> a(n);
    stack<int> s;
    rep(i, n) cin >> a[i];
    rep(i, n){
        if(!s.empty()){
            if(s.top() == a[i]){
                c++;
            }else{
                c = 0;
            }
        }
        s.push(a[i]);
        if(c == 3){
            rep(j, 4) s.pop();
            c = 0;
            int t[2];
            if(s.size() == 2){
                t[0] = s.top();
                s.pop();
                if(t[0] == s.top()){
                    c = 1;
                }
                s.push(t[0]);
            }else if(s.size() > 2){
                t[0] = s.top();
                s.pop();
                t[1] = s.top();
                s.pop();
                if(t[0] == t[1]){
                    c = 1;
                    if(t[1] == s.top()){
                        c = 2;
                    }
                }
                s.push(t[1]);
                s.push(t[0]);
            }
        }
    }
    
    cout << s.size() << endl;
} 
