#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll,ll> pl;
typedef tuple<ll,ll,ll> tupl;

int main()
{
    int n;
    cin >> n;
    vector<ll> cnt(1e6+2,0);
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b+1]--;
    }
    ll ans=cnt[0];
    for(int i=1;i<1e6+1;i++) {
        cnt[i]+=cnt[i-1];
        ans=max(ans,cnt[i]);
    }
    cout << ans << endl;
    return 0;
}
