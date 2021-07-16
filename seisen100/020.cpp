#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans=0;
    rep(i,n) {
        auto x=lower_bound(all(a),b[i]);
        auto y=upper_bound(all(c),b[i]);
        ans+=(x-a.begin())*(c.end()-y);
    }
    cout << ans << endl;
    return 0;
}
