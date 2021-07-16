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

const ll mod=1e5;

int digit_sum(int x) {
   int res = 0;
   while (x > 0) {
       res += x % 10;
       x /= 10;
   }
   return res;
}

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> v(mod);
    rep(i,mod) v[i]=(i+digit_sum(i))%mod;
    vector<int> ts(mod,-1);
    int nd=n,cnt=0;
    while(ts[nd]==-1) {
        ts[nd]=cnt;
        nd=v[nd];
        cnt++;
    } 
    int cycle=cnt-ts[nd];
    if(k>=ts[nd]) k=(k-ts[nd])%cycle+ts[nd];
    int ans;
    rep(i,mod) if(ts[i]==k) ans=i;
    cout << ans << endl;
    return 0;
}