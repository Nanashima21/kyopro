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
    vector<ll> v(3);
    rep(i,3) cin >> v[i];
    sort(all(v));
    ll ans=INF;
    for(int i=0;;i++) {
        if(v[2]*i>n) break;
        for(int j=0;;j++) {
            if(v[2]*i+v[1]*j>n) break;
            ll z=n-i*v[2]-j*v[1];
            if(z%v[0]==0&&z>=0) ans=min(ans,i+j+z/v[0]);
        }
    }
    cout << ans << endl;
    return 0;
}