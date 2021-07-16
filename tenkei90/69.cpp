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

int main()
{
    ll n,k;
    cin >> n >> k;
    if(n==1) {
        cout << k << endl;
        return 0;
    }
    ll ans=k*(k-1);
    ans%=mod;
    ans*=powmod(k-2,n-2);
    ans%=mod;
    cout << ans << endl;
    return 0;
}