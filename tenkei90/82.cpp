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

ll Div(ll a,ll b) {
    return (a*powmod(b,mod-2))%mod;
}

ll f(ll x) {
    ll v1=x%mod;
    ll v2=(x+1)%mod;
    ll v=v1*v2%mod;
    return Div(v,2);
}

int main()
{
    unsigned long long l,r;
    cin >> l >> r;
    unsigned long long pow10[22];
    pow10[0]=1;
    for(int i=1;i<=19;i++) pow10[i]=(10ULL*pow10[i-1]);
    ll ans=0;
    for(int i=1;i<=19;i++) {
        unsigned long long vl,vr;
        vl=max(l,pow10[i-1]);
        vr=min(r,pow10[i]-1ULL);
        if(vl>vr) continue;
        ll val=(f(vr)-f(vl-1)+mod)%mod;
        ans+=1LL*i*val;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}