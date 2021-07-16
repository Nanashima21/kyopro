#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

const ll mod=1000000007;

ll powmod(ll n,ll r) {
    ll num=1;
    while(r) {
        if(r&1) num=num*n%mod;
        n=n*n%mod;
        r/=2;
    }
    return num;
}

int main()
{
    int n,q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> v(n,0);
    for(int i=1;i<n;i++) {
        v[i]=v[i-1]+powmod(a[i-1],a[i]);
    } 
    vector<ll> c(n);
    rep(i,q) cin >> c[i];
    ll ans=v[c[0]-1];
    ans%=mod;
    for(int i=1;i<n;i++) {
        ans+=abs(v[c[i]-1]-v[c[i-1]-1]);
        ans%=mod;
    }
    ans+=v[c.back()-1]; 
    ans%=mod;  
    cout << ans << endl;
    return 0;
}