#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

ll gcd(ll x,ll y){
    if (y==0) return x;
    else return gcd(y,x%y);
}

ll lcm(ll x,ll y){
    return ll(x/gcd(x,y))*y;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    ll lc=1;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]/=2;
        lc=lcm(lc,a[i]);
    }
    rep(i,n) if((lc/a[i])%2==0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans=m/lc;
    ans=(ans+1)/2;
    cout << ans << endl;
    return 0;
}