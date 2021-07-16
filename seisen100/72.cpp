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

ll comb(ll n,ll r) {
    ll x=1,y=1;
    for(ll i=0;i<r;i++) x=x*(n-i)%mod;
    for(ll i=1;i<=r;i++) y=y*i%mod;
    return x*powmod(y,mod-2)%mod;
}

int main()
{
    int w,h;
    cin >> w >> h;
    w--; h--;
    cout << comb(w+h,h) << endl;
    return 0;
}