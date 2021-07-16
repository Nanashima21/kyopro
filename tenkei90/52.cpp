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

int main()
{
    int n;
    cin >> n;
    vector<ll> sum(n,0);
    rep(i,n) rep(j,6) {
        ll a;
        cin >> a;
        sum[i]+=a;
    }
    ll ans=1;
    rep(i,n) {
        ans*=sum[i];
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}