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

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n) cin >> x[i] >> y[i];
    ll ans=0;
    sort(all(x));
    sort(all(y));
    rep(i,n) {
        ans+=abs(x[i]-x[n/2]);
        ans+=abs(y[i]-y[n/2]);
    }
    cout << ans << endl;
    return 0;
}