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

const ll mod=1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n),cnt(n,0);
    rep(i,n) cin >> a[i];
    ll ans=1,x=3;
    rep(i,n) {
        if(a[i]!=0) {
            cnt[a[i]]++;
            ans*=cnt[a[i]-1];
          	cnt[a[i]-1]--;
          	ans%=mod;
        } else {
          	ans*=x;
          	x--;
          	ans%=mod;
            cnt[0]++;
        }
    }
    cout << ans << endl;
    return 0;
}