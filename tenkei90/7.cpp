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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    a.push_back(INF);
    ll q;
    cin >> q;
    rep(i,q) {
        ll b;
        cin >> b;
        auto x=lower_bound(all(a),b);
        int j=x-a.begin();
        ll ans=a[j]-b;
        if(j!=0) ans=min(ans,abs(b-a[j-1]));
        cout << ans << endl;
    }
    return 0;
}